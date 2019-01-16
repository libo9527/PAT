#include <cstdio>

int main(){
  int a[1010] = {0};
  int c, e;
  while(scanf("%d%d", &c, &e) != EOF){
    a[e] = c;
  }
  a[0] = 0;
  int count = 0;
  for(int i = 1; i <= 1000; i++){
    a[i-1] = a[i] * i;
    a[i] = 0;
    if(a[i-1] != 0){
      count++;
    }
  }
  if(count == 0){
    printf("0 0");
  }else{
    for(int i = 1000; i >= 0; i--){
      if(a[i] != 0){
        count--;
        if(count > 0){
          printf("%d %d ", a[i], i);
        }else{
          printf("%d %d", a[i], i);
        }
      }
    }
  }
  return 0;
}