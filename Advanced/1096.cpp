#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	ll sqr = sqrt(n), maxLen = 0, maxI;
	for(int i = 2; i <= sqr; i++) {
		ll j = i;
		ll temp = 1;
		while(1) {
			temp *= j;
			if(n % temp != 0) {
				break;
			} else if(j - i + 1 > maxLen) {
				maxLen = j - i + 1;
				maxI = i;
			}
			j++;
		}
	}
	if(maxLen == 0) {
		printf("1\n%lld", n);
	} else {
		printf("%lld\n", maxLen);
		for(ll i = 0; i < maxLen; i++) {
			printf("%lld", maxI + i);
			if(i < maxLen - 1) {
				printf("*");
			}
		}
	}
	return 0;
}