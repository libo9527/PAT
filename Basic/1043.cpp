#include <cstdio>
#include <cstring>

int main(){
  char words[10010];
  fgets(words, 10010, stdin);
  int len = strlen(words);
  int count[128] = {0}, num = 0;
  char s[7] = "PATest"; 
  for(int i = 0; i < len; i++){
    count[words[i]]++;
  }
  while(len--){
    for(int i = 0; i < 6; i++){
      if(count[s[i]] > 0){
        printf("%c", s[i]);
        count[s[i]]--;
      }
    }
  }
  return 0;
}