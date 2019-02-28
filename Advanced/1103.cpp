#include <cstdio>
#include <vector>
using namespace std;

int n, k, p, maxFacSum = -1;
vector<int> fac, temp, ans;

void dfs(int index, int nowK, int sum, int facSum) {
	if(sum == n && nowK == k) {
		if(facSum > maxFacSum) {
			maxFacSum = facSum;
			ans = temp;
		}
		return;
	}
	if(sum > n || nowK > k) {
		return;
	}
	if(index >= 1) {
		temp.push_back(index);
		dfs(index, nowK+1, sum + fac[index], facSum + index);
		temp.pop_back();
		dfs(index - 1, nowK, sum, facSum);
	}
}

int power(int x) {
	int i = p, t = 1;
	while(i--) {
		t *= x;
	}
	return t;
}

void init() {
	int i = 0, t = 0;
	while(t <= n) {
		fac.push_back(t);
		t = power(++i);
	}
}

int main() {
	scanf("%d%d%d", &n, &k, &p);
	init();
	dfs(fac.size() - 1, 0, 0, 0);
	if(maxFacSum == -1) {
		printf("Impossible\n");
	} else {
		printf("%d = %d^%d", n, ans[0], p);
		for(int i = 1; i < ans.size(); i++) {
			printf(" + %d^%d", ans[i], p);
		}
	}
	return 0;
}