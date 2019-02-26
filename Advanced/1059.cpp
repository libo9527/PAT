#include <cstdio>
#include <cmath>
const int maxn = 100010;

int num = 0;
struct Factor {
	int x, cnt;
} fac[10];

bool p[maxn] = {0};
int prime[maxn], pNum = 0;
void findPrime() {
	for(int i = 2; i < maxn; i++) {
		if(p[i] == false) {
			prime[pNum++] = i;
			for(int j = i + i; j < maxn; j += i) {
				p[j] = true;
			}
		}
	}
}

int main() {
	findPrime();
	int n;
	scanf("%d", &n);
	if(n == 1) {
		printf("1=1");
		return 0;
	}
	printf("%d=", n);
	int sqr = (int)sqrt(1.0 * n);
	for(int i = 0; i < pNum && prime[i] <= sqr; i++) {
		if(n % prime[i] == 0) {
			fac[num].x = prime[i];
			fac[num].cnt = 0;
			while(n % prime[i] == 0) {
				fac[num].cnt++;
				n /= prime[i];
			}
			num++;
		}
		if(n == 1) {
			break;
		}
	}
	if(n != 1) {
		fac[num].x = n;
		fac[num].cnt = 1;
		num++;
	}
	for(int i = 0; i < num; i++) {
		printf("%d", fac[i].x);
		if(fac[i].cnt > 1) {
			printf("^%d", fac[i].cnt);
		}
		if(i < num - 1) {
			printf("*");
		}
	}
	return 0;
}