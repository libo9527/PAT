#include <cstdio>

int main(){
  float a[1010] = {0};
  int k1, k2, count = 0;
  scanf("%d", &k1);
  int e;
  float c;
  while(k1--){
    scanf("%d%f", &e, &c);
    a[e] = c;
    count++;
  }
  scanf("%d", &k2);
  while(k2--){
    scanf("%d%f", &e, &c);
    if(a[e] != 0){
      a[e] += c;
      if(a[e] == 0){
        count--;
      }
    }else{
      a[e] += c;
      count++;
    }
  }
  if(count == 0){
    printf("0");
    return 0;
  }
  printf("%d ", count);
  for(int i = 1000; i >= 0; i--){
    if(a[i] != 0){
      printf("%d %.1f", i, a[i]);
      count--;
      if(count != 0){
        printf(" ");
      }
    }
  }
  return 0;
}