#include <cstdio>
#include <cstring>

int main(){
  char words[90][90];
  int num = 0;
  while(scanf("%s", words[num]) != EOF){
    num++;
  }
  for(int i = num - 1; i >= 0; i--){
    printf("%s", words[i]);
    if(i != 0) printf(" ");
  }
  return 0;
}