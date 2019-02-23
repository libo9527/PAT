#include <cstdio>
#include <cstring>

int main(){
  char words[1010];
  fgets(words, 1010, stdin);
  int len = strlen(words) - 1;
  int hashtable[128] = {0};
  for(int i = 0; i < len; i++){
    if(words[i] >= 'a' && words[i] <= 'z'){
      hashtable[words[i]]++;
    }else if(words[i] >= 'A' && words[i] <= 'Z'){
      hashtable[words[i] + 32]++;
    }
  }
  int idx = 0;
  for(int i = 1; i < 128; i++){
    if(hashtable[i] > hashtable[idx]){
      idx = i;
    }
  }
  printf("%c %d", idx, hashtable[idx]);
  return 0;
}