#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const long long INF = (1LL << 63) - 1;

long long map[256];
void init() {
	for(char c = '0'; c <= '9'; c++) {
		map[c] = c - '0';
	}
	for(char c = 'a'; c <= 'z'; c++) {
		map[c] = c - 'a' + 10;
	}
}

// radix进制的数转化为十进制
long long convertToTen(char s[], int radix, long long t) {
	int len = strlen(s);
	long long ans = 0;
	for(int i = 0; i < len; i++) {
		ans = ans * radix + map[s[i]];
		if(ans < 0 || ans > t) return -1;
	}
	return ans;
}

int findMax(char s[]) {
	int len = strlen(s);
	int ans = -1;
	for(int i = 0; i < len; i++) {
		if(map[s[i]] > ans) {
			ans = map[s[i]];
		}
	}
	return ans + 1;
}

int cmp(char s[], long long radix, long long n10) {
	long long num = convertToTen(s, radix, n10);
	if(num < 0) return 1;
	if(num > n10) return 1;
	else if(num < n10) return -1;
	else return 0;
}

long long binarySearch(char s[], long long left, long long right, long long n10) {
	while(left <= right) {
		long long mid = (left + right) / 2;
		int flag = cmp(s, mid, n10);
		if(flag == 0) {
			return mid;
		} else if(flag == 1) {
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}
	return -1;
}

int main() {
	init();
	char n1[20], n2[20], temp[20];
	int tag, radix;
	scanf("%s%s%d%d", n1, n2, &tag, &radix);
	if(tag == 2) {
		strcpy(temp, n1);
		strcpy(n1, n2);
		strcpy(n2, temp);
	}
	if(strcmp(n1, n2) == 0) {
		printf("%d", radix);
		return 0;
	}
	long long n1_10 = convertToTen(n1, radix, INF);
	long long low, high;
	low = findMax(n2);
	high = max(low, n1_10) + 1;
	long long ans = binarySearch(n2, low, high, n1_10);
	if(ans != -1) {
		printf("%d", ans);
	} else {
		printf("Impossible");
	}
	return 0;
}