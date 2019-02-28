#include <cstdio>
#include <cstring>
const int maxn = 1010;

struct BigNumber {
	int b[maxn], len;
	BigNumber() {
		memset(b, 0, sizeof(b));
		len = 0;
	}
};

BigNumber toBig(char a[]) {
	BigNumber bign;
	bign.len = strlen(a);
	for(int i = 0; i < bign.len; i++) {
		bign.b[i] = a[bign.len - i - 1] - '0';
	}
	return bign;
}

BigNumber divide(BigNumber bign, int b, int& r) {
	BigNumber ret;
	ret.len = bign.len;
	for(int i = bign.len - 1; i >= 0; i--) {
		r = r * 10 + bign.b[i];
		if(r < b) {
			ret.b[i] = 0;
		} else {
			ret.b[i] = r / b;
			r %= b;
		}
	}
	while(ret.len > 1 && ret.b[ret.len - 1] == 0) {
		ret.len--;
	}
	return ret;
}

void printBig(BigNumber bign) {
	for(int i = bign.len - 1; i >= 0; i--) {
		printf("%d", bign.b[i]);
	}
}

int main() {
	char a[maxn];
	int b;
	scanf("%s%d", a, &b);
	BigNumber bign = toBig(a);
	int r = 0;
	BigNumber ret = divide(bign, b, r);
	printBig(ret);
	printf(" %d", r);
	return 0;
}