#include <cstdio>
#include <map>
using namespace std;

int main() {
	int n, m, t;
	map<int, int> count;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%d", &t);
			if(count.find(t) != count.end()) {
				count[t]++;
			} else {
				count[t] = 1;
			}
		}
	}
	int maxn, maxc = 0;
	for(map<int, int>::iterator it = count.begin(); it != count.end(); it++) {
		if(it->second > maxc) {
			maxc = it->second;
			maxn = it->first;
		}
	}
	printf("%d", maxn);
	return 0;
}