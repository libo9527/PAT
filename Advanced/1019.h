#include <cstdio>

int main(){
  int n, b;
  scanf("%d%d", &n, &b);
  int ans[40], num = 0;
  do{
    ans[num++] = n % b;
    n /= b;
  }while(n != 0);
  bool flag = true;
  for(int i = 0; i <= num / 2; i++){
    if(ans[i] != ans[num - i - 1]){
      printf("No\n");
      flag = false;
      break;
    }
  }
  if(flag){
    printf("Yes\n");
  }
  for(int i = num - 1; i >= 0; i--){
    printf("%d", ans[i]);
    if(i != 0) printf(" ");
  }
  return 0;
}