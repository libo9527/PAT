#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int ans = 0;

int main() {
	// cnt 为除零以外未在本位的元素的个数
	// idx[] 为各元素所在的位置, 例如 0 所在的位置为 idx[0]
	// k 为除零以外未在本位的数
	int n, idx[maxn], cnt = 0, k = 1;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);
		idx[a] = i;
		if(a != 0 && i != a) {
			cnt++;
		}
	}
	while(cnt > 0) {
		if(idx[0] == 0) {
			while(k < n) {
				if(idx[k] != k) {
					swap(idx[0], idx[k]);
					ans++;
					break;
				}
				k++;
			}
		}
		while(idx[0] != 0) {
			swap(idx[0], idx[idx[0]]);
			ans++;
			cnt--;
		}
	}
	printf("%d", ans);
	return 0;
}