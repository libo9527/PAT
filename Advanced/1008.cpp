#include <cstdio>

const int maxn = 110;

int main(){
  int n, floor[maxn] = {0}, ans = 0;
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%d", &floor[i]);
  }
  for(int i = 1; i <= n; i++){
    if(floor[i] > floor[i - 1]){
      ans += (floor[i] - floor[i - 1]) * 6;
    }
    if(floor[i] < floor[i - 1]){
      ans += (floor[i - 1] - floor[i]) * 4;
    }
    ans += 5;
  }
  printf("%d", ans);
  return 0;
}