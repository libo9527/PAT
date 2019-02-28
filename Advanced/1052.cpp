#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;

struct node {
	int address, data, next;
	bool flag;
} nodes[maxn];

bool cmp(node n1, node n2) {
	if(!n1.flag || !n2.flag) {
		return n1.flag > n2.flag;
	} else {
		return n1.data < n2.data;
	}
}

int main() {
	for(int i = 0; i < maxn; i++) {
		nodes[i].flag = false;
	}
	int n, first, address;
	scanf("%d%d", &n, &first);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}
	int p = first, count = 0;
	while(p != -1) {
		nodes[p].flag = true;
		count++;
		p = nodes[p].next;
	}
	if(count == 0) {
		printf("0 -1");
	} else {
		sort(nodes, nodes + maxn, cmp);
		printf("%d %05d\n", count, nodes[0].address);
		for(int i = 0; i < count; i++) {
			if(i < count - 1) {
				printf("%05d %d %05d\n", nodes[i].address, nodes[i].data, nodes[i + 1].address);
			} else {
				printf("%05d %d -1\n", nodes[i].address, nodes[i].data);
			}
		}
	}
	return 0;
}