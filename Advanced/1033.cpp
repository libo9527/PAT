#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
struct Station {
	double distance;
	double price;
} stations[510], temp;

bool cmp(Station s1, Station s2) {
	return s1.distance < s2.distance;
}

int main() {
	double cmax, d, davg, ans = 0.0;
	int n;
	scanf("%lf%lf%lf%d", &cmax, &d, &davg, &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf%lf", &stations[i].price, &stations[i].distance);
	}
	stations[n].price = 0;
	stations[n].distance = d;
	sort(stations, stations + n + 1, cmp);
	if(stations[0].distance != 0) {
		printf("The maximum travel distance = 0.00");
		return 0;
	}
	// 当前加油站，当前油量，加满油最多能到的距离
	int now = 0;
	double nowTank = 0, maxDistance = stations[now].distance + cmax * davg;
	while(now < n) {
		// 距离当前加油站最近价格最低的加油站的下标及油价
		int index = -1;
		double minPrice = INF;
		for(int i = now + 1; i < n + 1 && stations[i].distance - stations[now].distance <= maxDistance; i++) {
			if(stations[i].price < minPrice) {
				index = i;
				minPrice = stations[i].price;
				if(minPrice < stations[now].price) {
					break;
				}
			}
		}
		if(index == -1) {
			break;
		}
		// 从当前站到下个站需要的油
		double need = (stations[index].distance - stations[now].distance) / davg;
		if(stations[index].price < stations[now].price) { // 下一个加油站油价更低，那在当前站就只加够到下个站的油
			if(nowTank < need) { // 当前油量不足
				ans += stations[now].price * (need - nowTank);
				nowTank = 0; // 开到下个站就没油了
			} else {
				nowTank -= need; // 开到下一站剩余的油
			}
		} else { // 当前站油价更低，在当前站加满油
			ans += stations[now].price * (cmax - nowTank);
			nowTank = cmax - need; // 开到下一站剩余的油
		}
		now = index;
	}
	if(now == n) {
		printf("%.2f", ans);
	} else {
		printf("The maximum travel distance = %.2f", stations[now].distance + maxDistance);
	}
	return 0;
}