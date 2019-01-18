#include <cstdio>

int main(){
  double ans[3], max, temp;
  char maxC;
  char b[3] = {'W', 'T', 'L'};
  for(int i = 0; i < 3; i++){
    max = 0.0;
    for(int j = 0; j < 3; j++){
      scanf("%lf", &temp);
      if(temp > max){
        max = temp;
        ans[i] = max;
        maxC = b[j];
      }
    }
    printf("%c ", maxC);
  }
  printf("%.2f", (ans[0]*ans[1]*ans[2]*0.65 - 1)*2);
  return 0;
}