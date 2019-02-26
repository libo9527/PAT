#include <cstdio>
#include <cmath>
const int maxn = 10010;

bool isPrime(int n) {
	if(n <= 1) {
		return false;
	} else {
		int sqr = (int) sqrt(1.0 * n);
		for(int i = 2; i <= sqr; i++) {
			if(n % i == 0) {
				return false;
			}
		}
		return true;
	}
}

int main() {
	int size, n, m;
	bool p[maxn] = {0};
	scanf("%d%d", &size, &n);
	while(isPrime(size) == false) {
		size++;
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &m);
		int idx = m % size;
		if(p[idx] == false) {
			p[idx] = true;
			if(i == 0) {
				printf("%d", idx);
			} else {
				printf(" %d", idx);
			}
		} else {
			int step, t;
			for(step = 1; step <= size; step++) {
				t = m + step * step;
				idx = t % size;
				if(p[idx] == false) {
					p[idx] = true;
					if(i == 0) {
						printf("%d", idx);
					} else {
						printf(" %d", idx);
					}
					break;
				}
			}
			if(step > size) {
				if(i == 0) {
					printf("-");
				} else {
					printf(" -");
				}
			}
		}
	}
	return 0;
}