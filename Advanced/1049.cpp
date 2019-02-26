#include <cstdio>

int main(){
  int n;
  scanf("%d", &n);
  int now, left, right, ans = 0, t = n, a = 1;
  while(t != 0){
    left = n / (a * 10);
    now = n % (a * 10) / a;
    right = n % a;
    if(now == 0){
      ans += left * a;
    }else if(now == 1){
      ans += left * a + right + 1;
    }else{
      ans += (left + 1) * a;
    }
    a *= 10;
    t /= 10;
  }
  printf("%d", ans);
  return 0;
}