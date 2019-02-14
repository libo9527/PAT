#include <cstdio>
#include <cmath>

int main(){
  int count, h;
  char c;
  scanf("%d %c", &count, &c);
  h = (int) sqrt((count + 1) / 2);
  for(int i = 0; i <= 2 * h - 2; i++){
    for(int j = 0; j <= 2 * h - 2; j++){
      if(i > j && i + j < 2 * h - 2 || i < j && i + j > 2 * h - 2){
        if(i > j && i + j < 2 * h - 2){
          printf(" ");
        }
      }else{
        printf("%c", c);
      }
    }
    printf("\n");
  }
  printf("%d\n", count - 2 * h * h + 1);
  return 0;
}