#include <cstdio>

int main(){
  int a;
  char b;
  scanf("%d %c", &a, &b);
  int c = a % 2 == 0 ? a/2 : a/2 + 1;
  for(int i = 0; i < c; i++){
    for(int j = 0; j < a; j++){
      if(i == 0||i==c-1){
        printf("%c", b);
      }else{
        if(j == 0||j == a - 1){
          printf("%c", b);
        }else{
          printf(" ");
        }
      }
    }
    if(i != c-1) printf("\n");
  }
  return 0;
}