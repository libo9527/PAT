#include <cstdio>
const char arr[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C'};

int main(){
  int a, b, c;
  scanf("%d %d %d", &a, &b, &c);
  printf("#%c%c%c%c%c%c", arr[a / 13], arr[a % 13], arr[b / 13], arr[b % 13], arr[c / 13], arr[c % 13]);
  return 0;
}