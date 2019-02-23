#include <cstdio>
#include <cstring>

int main(){
  char typed[100], out[100];
  scanf("%s%s", typed, out);
  int len1, len2;
  len1 = strlen(typed);
  len2 = strlen(out);
  int ans[128] = {0};
  for(int i = 0; i < len1; i++){
    bool flag = false;
    for(int j = 0; j < len2; j++){
      if(typed[i] == out[j]){
        flag = true;
      }
    }
    if(!flag){
      if(typed[i] >= 'a' && typed[i] <= 'z'){
        if(ans[typed[i] - 32] == 0){
          printf("%c", typed[i] - 32); 
          ans[typed[i] - 32] = 1;
        }
      }else {
        if(ans[typed[i]] == 0){
          printf("%c", typed[i]);
          ans[typed[i]] = 1;
        }
      }
    }
  }
  return 0;
}