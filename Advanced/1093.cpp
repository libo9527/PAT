#include <cstdio>
#include <cstring>

const int maxn = 100010;
const int mod = 1000000007;

int main() {
	char s[maxn];
	int numP[maxn] = {0}, numT = 0;
	int ans = 0;
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len; i++){
		if(i > 0){
			numP[i] = numP[i - 1];
		}
		if(s[i] == 'P'){
			numP[i]++;
		} 
	}	
	for(int i = len - 1; i >= 0; i--){
		if(s[i] == 'T'){
			numT++;
		}else if(s[i] == 'A'){
			ans = (ans + numP[i] * numT) % mod;
		}
	}
	printf("%d\n", ans);
	return 0;
}