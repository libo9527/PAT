#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
bool cmp(int a, int b) {
	if(a != b && a < 0 && b < 0) {
		return a < b;
	} else {
		return a > b;
	}
}

int main() {
	int nc, np, numc[maxn], nump[maxn];
	long long ans = 0; // 设为 int 会有一条测试答案错误
	scanf("%d", &nc);
	for(int i = 0; i < nc; i++) {
		scanf("%d", &numc[i]);
	}
	scanf("%d", &np);
	for(int i = 0; i < np; i++) {
		scanf("%d", &nump[i]);
	}
	sort(numc, numc + nc, cmp);
	sort(nump, nump + np, cmp);
	int i = 0, j = 0;
	while(i < nc && j < np) {
		if(numc[i] * nump[j] > 0) {
			ans += numc[i] * nump[j];
			i++;
			j++;
		} else if(numc[i] == 0) {
			i++;
		} else if(nump[j] == 0) {
			j++;
		}	else if(numc[i] > 0 && nump[j] < 0) {
			i++;
		} else if(numc[i] < 0 && nump[j] > 0) {
			j++;
		} else {
			i++;
			j++;
		}
	}
	printf("%d", ans);
	return 0;
}