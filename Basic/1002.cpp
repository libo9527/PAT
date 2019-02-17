#include <cstdio>
#include <cstring>

const char arr[10][10] = {{'l', 'i', 'n', 'g'}, {'y', 'i'}, {'e', 'r'}, {'s', 'a', 'n'}, {'s', 'i'}, {'w', 'u'}, {'l', 'i', 'u'}, {'q', 'i'}, {'b', 'a'}, {'j', 'i', 'u'}};

int main(){
  char str[110];
  fgets(str, 110, stdin);
  int sum = 0, num = 0, len = strlen(str), ans[10];
  for(int i = 0; i < len - 1; i++){
    sum += str[i] - '0';
  }
  do{
    ans[num++] = sum % 10;
    sum /= 10;
  }while(sum != 0);
  for(int i = num - 1; i >= 0; i--){
    printf("%s", arr[ans[i]]);
    if(i != 0) printf(" ");
  }
  return 0;
}