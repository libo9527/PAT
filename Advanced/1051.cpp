#include <cstdio>
#include <stack>
using namespace std;

const int maxn = 1010;

stack<int> in;
int out[maxn];
int main() {
	int m, n, k;
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; i++) {
		while(!in.empty()) {
			in.pop();
		}
		for(int j = 1; j <= n; j++) {
			scanf("%d", &out[j]);
		}
		while(!in.empty()) {
			in.pop();
		}
		int current = 1;
		bool flag = true;
		for(int q = 1; q <= n; q++) {
			in.push(q);
			if(in.size() > m) {
				flag = false;
				break;
			}
			while(!in.empty() && in.top() == out[current]) {
				in.pop();
				current++;
			}
		}
		if(in.empty() && flag) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}