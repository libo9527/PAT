\#include <cstdio>
#include <cstring>
const int maxn = 25;

struct BigNumber {
	int d[maxn], len;
	BigNumber() {
		memset(d, 0, sizeof(d));
		len = 0;
	}
};

BigNumber toBig(char a[]) {
	BigNumber bign;
	bign.len = strlen(a);
	for(int i = 0; i < bign.len; i++) {
		bign.d[i] = a[bign.len - i - 1] - '0';
	}
	return bign;
}

BigNumber mutiby(BigNumber bign, int b) {
	BigNumber ret;
	int carry = 0;
	for(int i = 0; i < bign.len; i++) {
		int temp = bign.d[i] * b + carry;
		ret.d[ret.len++] = temp % 10;
		carry = temp / 10;
	}
	while(carry != 0) {
		ret.d[ret.len++] = carry % 10;
		carry /= 10;
	}
	return ret;
}

int main() {
	char n[maxn];
	scanf("%s", n);
	BigNumber bign = toBig(n);
	BigNumber ret = mutiby(bign, 2);
	if(ret.len != bign.len) {
		printf("No\n");
	} else {
		bool t[maxn] = {0};
		int i, j;
		for(i = 0; i < ret.len; i++) {
			bool flag = false;
			for(j = 0; j < bign.len; j++) {
				if(bign.d[i] == ret.d[j] && t[j] == false) {
					t[j] = true;
					flag = true;
					break;
				}
			}
			if(!flag) {
				break;
			}
		}
		if(i < ret.len - 1) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	for(int i = ret.len - 1; i >= 0; i--) {
		printf("%d", ret.d[i]);
	}
	return 0;
}