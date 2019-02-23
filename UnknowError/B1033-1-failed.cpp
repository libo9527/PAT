#include <cstdio>
#include <cstring>

int main(){
  char broken[40], words[100010];
  scanf("%s%s", broken, words);
  int len1, len2;
  len1 = strlen(broken);
  len2 = strlen(words);
  bool hashtable[128] = {false};
  for(int i = 0; i < len1; i++){
    if(broken[i] >= 'a' && broken[i] <= 'z'){
      hashtable[broken[i] - 32] = true;
    }
    if(broken[i] >= 'A' && broken[i] <= 'Z'){
      hashtable[broken[i] + 32] = true;
    }
    hashtable[broken[i]] = true;
  }
  for(int i = 0; i < len2; i++){
    if(hashtable['+'] && words[i] >= 'A' && words[i] <= 'Z'){
      continue;
    }
    if(hashtable[words[i]]){
      continue;
    }
    printf("%c", words[i]);
  }
  printf("\n");
  return 0;
}

-----------------------------------------------------------------

#include <cstdio>
#include <cstring>

int main(){
  char broken[100010], words[100010];
  // scanf("%s%s", broken, words); case3中的空格没有用'_'来代替，所以导致出错！！！
  fgets(broken, 100010, stdin);
  fgets(words, 100010, stdin);
  int len1, len2;
  len1 = strlen(broken) - 1;
  len2 = strlen(words) - 1;
  bool hashtable[256];
  memset(hashtable, true, sizeof(hashtable));
  for(int i = 0; i < len1; i++){
    if(broken[i] >= 'A' && broken[i] <= 'Z'){
      broken[i] = broken[i] - 'A' + 'a';
    }
    hashtable[broken[i]] = false;
  }
  for(int i = 0; i < len2; i++){
    if(words[i] >= 'A' && words[i] <= 'Z'){
      int low = words[i] - 'A' + 'a';
      if(hashtable[low] == true && hashtable['+'] == true){
        printf("%c", words[i]);
      }
    }else if (hashtable[words[i]] == true){
      printf("%c", words[i]);
    }
  }
  printf("\n");
  return 0;
}