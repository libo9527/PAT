#include <cstdio>

int main(){
  int a;
  scanf("%d", &a);
  int b = a / 100;
  for(int i = 0; i < b; i++){
    printf("B");
  }
  int s = a % 100 / 10;
  for(int i = 0; i < s; i++){
    printf("S");
  }
  int g = a % 10;
  for(int i = 1; i <= g; i++){
    printf("%d", i);
  }
  return 0;
}