#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;

int n, p;
long long num[maxn];
int binarySearch(int i, long long x) {
	if(num[n - 1] <= x) return n;
	int left = i + 1, right = n - 1, mid;
	while(left < right) {
		mid = left + (right - left) / 2;
		if(num[mid] > x) {
			right = mid;
		} else {
			left = mid + 1;
		}
	}
	return left;
}

int main() {
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
	}
	sort(num, num + n);
	int ans = 1;
	for(int i = 0; i < n; i++) {
		int j = binarySearch(i, num[i] * p);
		ans = max(ans, j - i);
	}
	printf("%d", ans);
	return 0;
}