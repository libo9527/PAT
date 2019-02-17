#include <cstdio>
#include <cstring>

int main(){
  char before[10010];
  scanf("%s", before);
  int len = strlen(before);
  int pos;
  for(int i = 0; i < len; i++){
    if(before[i] == 'E'){
      pos = i;
      break;
    }
  }
  if(before[0] == '-') {
    printf("-");
  }
  int exp = 0;
  for(int i = pos + 2; i < len; i++){
    exp = exp * 10 + (before[i] - '0');
  }
  if(exp == 0){
    for(int i = 1; i < pos; i++){
      printf("%c", before[i]);
    }
  }else if(before[pos + 1] == '+'){
    printf("%c", before[1]);
    if(exp >= pos - 3){
      for(int i = 3; i < pos; i++){
        printf("%c", before[i]);
      }
      for(int i = 0; i < exp - pos + 3; i++){
        printf("0");
      }
    }else{
      for(int i = 3; i < exp + 3; i++){
        printf("%c", before[i]);
      }
      printf(".");
      for(int i = exp + 3; i < pos; i++){
        printf("%c", before[i]);
      }
    }
  }else {
    printf("0.");
    for(int i = 0; i < exp - 1; i++){
      printf("0");
    }
    for(int i = 1; i < pos; i++){
     if(before[i] != '.'){
      printf("%c", before[i]);
     }
    }
  }
  return 0;
}