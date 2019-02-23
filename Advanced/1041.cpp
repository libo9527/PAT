#include <cstdio>

int main(){
  int n, nums[100010], count[10010] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &nums[i]);
    count[nums[i]]++;
  }
  bool flag = false;
  for(int i = 0; i < n; i++){
    if(count[nums[i]] == 1){
      printf("%d", nums[i]);
      flag = true;
      break;
    }
  }
  if(!flag){
    printf("None");
  }
  return 0;
}