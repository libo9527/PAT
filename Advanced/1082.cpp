#include <cstdio>
#include <cstring>
const char shu[20][10] = {{"ling"}, {"yi"}, {"er"}, {"san"}, {"si"}, {"wu"}, {"liu"}, {"qi"}, {"ba"}, {"jiu"}};
const char wei[20][10] = {{"Shi"}, {"Bai"}, {"Qian"}, {"Wan"}, {"Yi"}};

int main(){
  char n[15];
  scanf("%s", &n);
  int len = strlen(n);
  int left = 0, right = len - 1;
  if(n[0] == '-'){
    printf("Fu");
    left++;
  }
  while(left + 4 <= right){
    right -= 4;
  }
  while(left < len){
    bool isPrint = false;
    bool flag = false;
    while(left <= right){
      if(left > 0 && n[left] == '0'){
        flag = true;
      }else{
        if(left != 0){
          printf(" ");
        }
        if(flag){
          printf("ling ");
          flag = false;
        }
        isPrint = true;
        printf("%s", shu[n[left] - '0']);
        if(right != left){
          printf(" %s", wei[right - left - 1]);
        }
      }
      left++;
    }
    if(isPrint && left != len){
      printf(" %s", wei[(len - right - 1) / 4 + 2]);
      isPrint = false;
    }
	right += 4;
  }
  return 0;
}