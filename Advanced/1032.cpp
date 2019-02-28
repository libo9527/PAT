#include <cstdio>

const int maxn = 100010;

struct node {
	char data;
	int next;
	bool flag;
} nodes[maxn];

int main() {
	for(int i = 0; i < maxn; i++) {
		nodes[i].flag = false;
	}
	int add1, add2, n;
	scanf("%d%d%d", &add1, &add2, &n);
	int address, next;
	char data;
	for(int i = 0; i < n; i++) {
		scanf("%d %c %d", &address, &data, &next);
		nodes[address].data = data;
		nodes[address].next = next;
	}
	int p = add1;
	while(p != -1) {
		nodes[p].flag = true;
		p = nodes[p].next;
	}
	p = add2;
	while(p != -1) {
		if(nodes[p].flag) {
			break;
		}
		p = nodes[p].next;
	}
	if(p != -1) {
		printf("%05d", p);
	} else {
		printf("-1");
	}
	return 0;
}