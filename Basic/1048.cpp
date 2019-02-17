#include <cstdio>
#include <cstring>
const char arr[15] = "0123456789JQK";
void reverse(char a[], int len){
  for(int i = 0; i < len / 2; i++){
    char temp = a[i];
    a[i] = a[len - i - 1];
    a[len - i - 1] = temp;
  }
}

int main(){
  char a[110], b[110], ans[110];
  scanf("%s %s", a, b);
  int lena = strlen(a);
  int lenb = strlen(b);
  reverse(a, lena);
  reverse(b, lenb);
  int len = lena > lenb ? lena : lenb;
  int num = 0, numa, numb;
  for(int i = 0; i < len; i++){
    numa = i < lena ? a[i] - '0' : 0;
    numb = i < lenb ? b[i] - '0' : 0;
    if (num % 2 == 0){
      ans[num++] = arr[(numa + numb) % 13];
    }else{
      int temp = numb - numa;
      if(temp < 0) temp += 10;
      ans[num++] = temp + '0';
    }
  }
  for(int i = num - 1; i >= 0; i--){
    printf("%c", ans[i]);
  }
  return 0;
}