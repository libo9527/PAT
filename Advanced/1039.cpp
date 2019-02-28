#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 26 * 26 * 26 * 10 + 1;
vector<int> students[maxn];

int toId(char s[]) {
	int id = 0;
	for(int i = 0; i < 3; i++) {
		id = id * 26 + (s[i] - 'A');
	}
	id = id * 10 + (s[3] - '0');
	return id;
}

int main() {
	int n, k;
	char name[5];
	scanf("%d%d", &n, &k);
	for(int i = 0; i < k; i++) {
		int cid, cnt;
		scanf("%d%d", &cid, &cnt);
		for(int j = 0; j < cnt; j++) {
			scanf("%s", name);
			int sid = toId(name);
			students[sid].push_back(cid);
		}
	}
	for(int i = 0; i < n; i++) {
		scanf("%s", name);
		int sid = toId(name);
		printf("%s %d", name, students[sid].size());
		sort(students[sid].begin(), students[sid].end());
		for(int j = 0; j < students[sid].size(); j++) {
			printf(" %d", students[sid][j]);
		}
		printf("\n");
	}
	return 0;
}