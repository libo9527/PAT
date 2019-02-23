#include <cstdio>
#include <cstring>

int main(){
  char ch1[10010], ch2[10010];
  fgets(ch1, 10010, stdin);
  fgets(ch2, 10010, stdin);
  int len1 = strlen(ch1);
  int len2 = strlen(ch2);
  bool hashtable[128];
  memset(hashtable, true, sizeof(hashtable));
  for(int i = 0; i < len2; i++){
    hashtable[ch2[i]] = false;
  }
  for(int i = 0; i < len1; i++){
    if(hashtable[ch1[i]]){
      printf("%c", ch1[i]);
    }
  }
  return 0;
}