#include <cstdio>

const int maxn = 100010;
const int INF = (1 << 31) - 1;
int sum[maxn];

int lower_bound(int left, int right, int x){
	while(left < right){
	  int mid = left + (right - left) / 2;
	  if(sum[mid] >= x){
	    right = mid;
	  }else{
	    left = mid + 1;
	  }
	}
	return left;
}

int main(){
  int n, m;
  sum[0] = 0;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i++){
    int t;
    scanf("%d", &t);
    sum[i] = sum[i - 1] + t;
  }
  int near = INF;
  for(int i = 1; i <= n; i++){
    int j = lower_bound(i, n + 1, m + sum[i - 1]);
    if(sum[j] - sum[i - 1] == m){
      near = m;
      break;
    }else if(sum[j] - sum[i - 1] > m && sum[j] - sum[i - 1] < near){
      near = sum[j] - sum[i - 1];
    }
  }
  for(int i = 1; i <= n; i++){
    int j = lower_bound(i, n + 1, sum[i - 1] + near);
    if(sum[j] - sum[i - 1] == near){
      printf("%d-%d\n", i, j);
    }
  }
  return 0;
}