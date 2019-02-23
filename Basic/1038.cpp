#include <cstdio>

int main(){
  int n, k, temp, score[111] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &temp);
    score[temp]++;
  }
  scanf("%d", &k);
  for(int i = 0; i < k; i++){
    scanf("%d", &temp);
    printf("%d", score[temp]);
    if(i < k - 1){
      printf(" ");
    }
  }
  return 0;
}