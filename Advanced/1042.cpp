#include <cstdio>

int main(){
  int k;
  scanf("%d", &k);
  int start[54], end[54], next[54];
  for(int i = 0; i < 54; i++){
    scanf("%d", &next[i]);
  }
  for(int i = 0; i < 54; i++){
    start[i] = i;
  }
  for(int i = 0; i < k; i++){
    for(int j = 0; j < 54; j++){
      end[next[j]-1] = start[j];
    }
    for(int k = 0; k < 54; k++){
      start[k] = end[k];
    }
  }
  char huase[5] = {'S', 'H', 'C', 'D', 'J'};
  for(int i = 0; i < 54; i++){
    if(i < 53){
      printf("%c%d ", huase[start[i]/13], start[i]%13 + 1);
    }else{
      printf("%c%d\n", huase[start[i]/13], start[i]%13 + 1);
    }
  }
  return 0;
}