#include <cstdio>
#include <cstring>
void reverse(char a[], int len){
  for(int i = 0; i < len / 2; i++){
    char temp = a[i];
    a[i] = a[len - i - 1];
    a[len - i - 1] = temp;
  }
}

int main(){
  int n;
  scanf("%d", &n);
  char centence[110][300], ans[300];
  int len[110], num = 0, minlen = 300;
  getchar();
  for(int i = 0; i < n; i++){
    fgets(centence[i], 300, stdin);
    len[i] = strlen(centence[i]) - 1;
    if(len[i] < minlen) minlen = len[i];
    reverse(centence[i], len[i]);
  }
  bool flag = true;
  for(int k = 0; k < minlen; k++){
    char c = centence[0][k];
    for(int j = 0; j < n; j++){
      if(centence[j][k] != c){
        flag = false;
        break;
      }
    }
    if(flag){
      ans[num++] = c;
    }else{
      break;
    }
  }
  if(num == 0){
    printf("nai");
  }else{
    for(int i = num - 1; i >= 0; i--){
      printf("%c", ans[i]);
    }
  }
  return 0;
}