#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn = 15;

int n;
int num = 0;
bool notRoot[maxn] = {0};

struct Node {
	int left, right;
} nodes[maxn];

int toNum(char c) {
	if(c == '-') {
		return -1;
	} else {
		notRoot[c - '0'] = true;
		return c - '0';
	}
}

int findRoot() {
	for(int i = 0; i < n; i++) {
		if(notRoot[i] == false) {
			return i;
		}
	}
}

void postTravel(int root) {
	if(root == -1) {
		return;
	}
	postTravel(nodes[root].left);
	postTravel(nodes[root].right);
	swap(nodes[root].left, nodes[root].right);
}

void levelRravel(int root) {
	queue<int> q;
	q.push(root);
	while(!q.empty()) {
		int now = q.front();
		q.pop();
		num++;
		printf("%d", now);
		if(num < n) {
			printf(" ");
		}
		if(nodes[now].left != -1) {
			q.push(nodes[now].left);
		}
		if(nodes[now].right != -1) {
			q.push(nodes[now].right);
		}
	}
}

void inTravel(int root) {
	if(root == -1) {
		return;
	}
	inTravel(nodes[root].left);
	printf("%d", root);
	num++;
	if(num < n) {
		printf(" ");
	}
	inTravel(nodes[root].right);
}

int main() {
	char left, right;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%*c%c %c", &left, &right);
		nodes[i].left = toNum(left);
		nodes[i].right = toNum(right);
	}
	int root = findRoot();
	postTravel(root);
	levelRravel(root);
	num = 0;
	printf("\n");
	inTravel(root);
	return 0;
}