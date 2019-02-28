#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
struct node {
	int address, data, next;
	int order;
} nodes[maxn];

bool cmp(node n1, node n2) {
	return n1.order < n2.order;
}

int main() {
	for(int i = 0; i < maxn; i++) {
		nodes[i].order = maxn;
	}
	int firstAD, n, k, address;
	scanf("%d%d%d", &firstAD, &n, &k);
	for(int i = 0; i < n; i++) {
		scanf("%d", &address);
		scanf("%d%d", &nodes[address].data, &nodes[address].next);
		nodes[address].address = address;
	}
	int p = firstAD, count = 0;
	while(p != -1) {
		nodes[p].order = count++;
		p = nodes[p].next;
	}
	sort(nodes, nodes + maxn, cmp);
	for(int i = 0; i < count / k; i++) {
		for(int j = (i + 1) * k - 1; j > i * k; j--) {
			printf("%05d %d %05d\n", nodes[j].address, nodes[j].data, nodes[j - 1].address);
		}
		printf("%05d %d ", nodes[i * k].address, nodes[i * k].data);
		if(i < count / k - 1) {
			printf("%05d\n", nodes[(i + 2) * k - 1].address);
		} else {
			if(count % k == 0) {
				printf("-1\n");
			} else {
				printf("%05d\n", nodes[(i + 1) * k].address);
				for(int j = (i + 1) * k; j < count; j++) {
					printf("%05d %d ", nodes[j].address, nodes[j].data);
					if(j < count - 1) {
						printf("%05d\n", nodes[j + 1].address);
					} else {
						printf("-1\n");
					}
				}
			}
		}
	}
	return 0;
}