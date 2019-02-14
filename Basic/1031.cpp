#include <stdio.h>
#include <string.h>

int main(){
  int n, n1, n2;
  char a[100];
  gets(a);
  n = strlen(a);
  n1 = (n + 2) / 3;
  n2 = n + 2 - 2 * n1; 
  for(int i = 0; i < n1 - 1; i++){
    printf("%c", a[i]);
    for(int j = 0; j < n2 - 2; j++){
      printf(" ");
    }
    printf("%c\n", a[n - 1 - i]);
  }
  for(int i = 0; i < n2; i++){
    printf("%c", a[n1 - 1 + i]);
  }
  return 0;
}