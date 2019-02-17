#include <cstdio>

int main(){
  int a, b, sum = 0;
  scanf("%d %d", &a, &b);
  sum = a + b;
  char ans[10000];
  int num = 0;
  if(sum < 0){
    printf("-");
    sum = -sum;
  }
  do{
    ans[num++] = sum % 10 + '0';
    sum /= 10;
  }while(sum != 0);
  for(int i = num - 1; i >= 0; i--){
    printf("%c", ans[i]);
    if(i > 0 && i % 3 == 0){
      printf(",");
    }
  }
  return 0;
}