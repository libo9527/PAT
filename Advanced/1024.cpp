#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct BigNumber {
	int d[1000], len;
	BigNumber() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

BigNumber toBig(char a[]) {
	BigNumber ret;
	ret.len = strlen(a);
	for(int i = 0; i < ret.len; i++) {
		ret.d[i] = a[ret.len - i - 1] - '0';
	}
	return ret;
}

bool check(BigNumber bign) {
	for(int i = 0; i <= bign.len / 2; i++) {
		if(bign.d[i] != bign.d[bign.len - i - 1]) {
			return false;
		}
	}
	return true;
}

BigNumber sum(BigNumber a, BigNumber b) {
	BigNumber c;
	int carry = 0;
	for(int i = 0; i < a.len || i < b.len; i++) {
		int t = a.d[i] + b.d[i] + carry;
		c.d[c.len++] = t % 10;
		carry = t / 10;
	}
	if(carry != 0) {
		c.d[c.len++] = carry;
	}
	return c;
}

int main() {
	char a[1000];
	int maxc, c = 0;
	scanf("%s%d", a, &maxc);
	BigNumber b = toBig(a);
	while(c < maxc && check(b) == false) {
		BigNumber t = b;
		reverse(b.d, b.d + b.len);
		b = sum(b, t);
		c++;
	}
	for(int i = b.len - 1; i >= 0; i--) {
		printf("%d", b.d[i]);
	}
	printf("\n%d", c);
	return 0;
}