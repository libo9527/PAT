#include <cstdio>

struct Poly{
  int exp;
  double coef;
} poly[1111];
double ans[2222];
int main(){
  int k1, k2, count = 0;
  scanf("%d", &k1);
  for(int i = 0; i < k1; i++){
    scanf("%d%lf", &poly[i].exp, &poly[i].coef);
  }
  scanf("%d", &k2);
  int exp;
  double coef;
  for(int i = 0; i < k2; i++){
    scanf("%d%lf", &exp, &coef);
    for(int j = 0; j < k1; j++){
      ans[exp + poly[j].exp] += coef * poly[j].coef;
    }
  }
  for(int i = 0; i < 2222; i++){
    if(ans[i] != 0){
      count++;
    }
  }
  printf("%d", count);
  for(int i = 2222; i >= 0; i--){
    if(ans[i] != 0){
      printf(" %d %.1f", i, ans[i]);
    }
  }
  return 0;
}