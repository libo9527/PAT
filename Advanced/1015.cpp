#include <cstdio>
#include <cmath>
const int maxn = 100010;

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
	int n, radix;
	while(scanf("%d", &n) != EOF) {
		if(n < 0) break;
		scanf("%d", &radix);
		if(isPrime(n) == false) {
			printf("No\n");
		} else {
			int d[maxn], num = 0;
			do {
				d[num++] = n % radix;
				n /= radix;
			} while(n != 0);
			for(int i = 0; i < num; i++) {
				n = n * radix + d[i];
			}
			if(isPrime(n)) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}