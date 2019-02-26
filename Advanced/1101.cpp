#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 100010;
const int INF = (1 << 31) - 1; 

int main(){
	int n, num[maxn], leftMax[maxn] = {0}, rightMin[maxn], count = 0, ans[maxn];
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &num[i]);
	}	
	for(int i = 0; i <= n - 2; i++){
		if(i == 0){
			leftMax[i + 1] = num[i];
		}else{
			leftMax[i + 1] = max(leftMax[i - 1], num[i]);
		}
	}
	rightMin[n - 1] = INF;
	for(int i = n - 1; i >= 1; i--){
		if(i == n - 1){
			rightMin[i - 1] = num[i];
		}else{
			rightMin[i - 1] = min(rightMin[i + 1], num[i]); 
		}
	}
	for(int i = 0; i < n; i++){
		if(num[i] > leftMax[i] && num[i] < rightMin[i]){
			ans[count++] = num[i];
		}
	}
	printf("%d\n", count);
	for(int i = 0; i < count; i++){
		printf("%d", ans[i]);
		if(i < count - 1){
			printf(" ");
		} 
	}
	printf("\n");
	return 0;
}