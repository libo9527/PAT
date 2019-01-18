#include <cstdio>

int main(){
  int n;
  scanf("%d", &n);
  int a[100010] = {0};
  int maxScore = 0, maxIdx = -1, idx, score;
  for (int i = 0; i < n; i++){
    scanf("%d%d", &idx, &score);
    a[idx] += score;
    if(a[idx] > maxScore){
      maxScore = a[idx];
      maxIdx = idx;
    }
  }
  printf("%d %d", maxIdx, maxScore);
  return 0;
}