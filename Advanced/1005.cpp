#include <cstdio>
#include <cstring>
const char num[10][10] = {{"zero"}, {"one"}, {"two"}, {"three"}, {"four"}, {"five"}, {"six"}, {"seven"}, {"eight"}, {"nine"}};

int main(){
  char n[111];
  scanf("%s", n);
  int len = strlen(n), sum = 0;
  for(int i = 0; i < len; i++){
    sum += n[i] - '0';
  }
  int ans[10];
  int count = 0;
  do{
    ans[count++] = sum % 10;
    sum /= 10;
  }while(sum);
  for(int i = count - 1; i >= 0; i--){
    printf("%s", num[ans[i]]);
    if(i != 0){
      printf(" ");
    }
  }
  return 0;
}