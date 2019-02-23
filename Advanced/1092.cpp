#include <cstdio>
#include <cstring>

int main(){
  char arr1[1111], arr2[1111];
  scanf("%s%s", arr1, arr2);
  int len1, len2;
  len1 = strlen(arr1);
  len2 = strlen(arr2);
  int ans, hashtable[128] = {0};
  for(int i = 0; i < len2; i++){
    hashtable[arr2[i]]++;
  }
  for(int i = 0; i < len1; i++){
    hashtable[arr1[i]]--;
  }
  for(int i = 0; i < 128; i++){
    if(hashtable[i] > 0){
      ans += hashtable[i];
    }
  }
  if(ans == 0){
    printf("Yes %d", len1 - len2);
  }else{
    printf("No %d", ans);
  }
  return 0;
}