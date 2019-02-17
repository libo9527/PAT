#include <cstdio>
#include <cstring>
 int wight[20] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
 char code[15] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};

int main(){
  int n;
  scanf("%d", &n);
  bool flag = true;
  for(int i = 0; i < n; i++){
    char card[20];
    scanf("%s", card);
    int j, sum = 0;
    for(j = 0; j < 17; j++){
      if(card[j] >= '0' && card[j] <= '9'){
        sum += (card[j] - '0') * wight[j];
      }else{
        break;
      }
    }
    if(j < 17 || card[17] != code[sum % 11]){
      printf("%s\n", card);
      flag = false;
    }
  }
  if(flag){
    printf("All passed\n");
  }
  return 0;
}