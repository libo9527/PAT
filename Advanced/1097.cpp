#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
bool isExist[maxn] = {0};

struct node {
	int address, data, next, order;
} nodes[maxn];

bool cmp(node n1, node n2) {
	return n1.order < n2.order;
}

int main() {
	for(int i = 0; i < maxn; i++) {
		nodes[i].order = 2 * maxn;
	}
	int n, first, address;
	scanf("%d%d", &first, &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}
	int p = first, countV = 0, countR = 0;
	while(p != -1) {
		if(isExist[abs(nodes[p].data)] == false) {
			nodes[p].order = countV++;
			isExist[abs(nodes[p].data)] = true;
		} else {
			nodes[p].order = maxn + countR++;
		}
		p = nodes[p].next;
	}
	sort(nodes, nodes + maxn, cmp);
	for(int i = 0; i < countV + countR; i++) {
		if(i != countV - 1 && i != countV + countR - 1) {
			printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i + 1].address);
		} else {
			printf("%05d %d -1\n", nodes[i].address, nodes[i].data);
		}
	}
	return 0;
}