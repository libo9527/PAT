#include <cstdio>
#include <cstring>

int main(){
  int n;
  char s[110];
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s", s);
    int len = strlen(s);
    int numP = 0, numO = 0, numT = 0;
    int posP = -1, posT = -1;
    for(int j = 0; j < len; j++){
      if(s[j] == 'P'){
        numP++;
        posP = j;
      }else if(s[j] == 'T'){
        numT++;
        posT = j;
      }else if(s[j] != 'A'){
        numO++;
      }
    }
    if(numP != 1 || numT != 1 || numO != 0 || posT - posP <= 1){
      printf("NO\n");
      continue;
    }
    int x = posP, y = posT - posP - 1, z = len - posT - 1;
    if(x * y == z){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}