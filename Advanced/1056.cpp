#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

struct Mouse {
	int w, r;
} mouses[maxn];

queue<int> q;

int main() {
	int np, ng;
	scanf("%d%d", &np, &ng);
	for(int i = 0; i < np; i++) {
		scanf("%d", &mouses[i].w);
	}
	int a;
	for(int i = 0; i < np; i++) {
		scanf("%d", &a);
		q.push(a);
	}
	int tempNP = np, group;
	while(q.size() != 1) {
		if(tempNP % ng == 0) {
			group = tempNP / ng;
		} else {
			group = tempNP / ng + 1;
		}
		int idx;
		for(int i = 0; i < group; i++) {
			idx = q.front();
			for(int j = 0; j < ng; j++) {
				if(i * ng + j >= tempNP) {
					break;
				}
				if(mouses[q.front()].w > mouses[idx].w) {
					idx = q.front();
				}
				mouses[q.front()].r = group + 1;
				q.pop();
			}
			q.push(idx);
		}
		tempNP = group;
	}
	mouses[q.front()].r = 1;
	for(int i = 0; i < np; i++) {
		printf("%d", mouses[i].r);
		if(i < np - 1) {
			printf(" ");
		}
	}
	return 0;
}