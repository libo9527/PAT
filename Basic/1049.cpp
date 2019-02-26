#include <cstdio>

const int maxn = 100010;

int n;
double num[maxn], ans = 0.0;
int main(){
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%lf", &num[i]);
  }
  for(int i = 0; i < n; i++){
    ans += num[i] * (i + 1) * (n - i);
  }
  printf("%.2f", ans);
  return 0;
}