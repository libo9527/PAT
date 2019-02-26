#include <cstdio>
#include <algorithm>
using namespace std;

void toArray(int num, int array[]){
  for(int i = 0; i < 4; i++){
    array[i] = num % 10;
    num /= 10;
  }
}

int toNumber(int array[]){
  int ans = 0;
  for(int i = 3; i >= 0; i--){
    ans = ans * 10 + array[i];
  }  
  return ans;
}

bool cmp(int a, int b){
  return a > b;
}

int increase(int num){
  int array[4] = {0};
  toArray(num, array);
  sort(array, array + 4, cmp);
  return toNumber(array);
}
  
int decrease(int num){
  int array[4] = {0};
  toArray(num, array);
  sort(array, array + 4);
  return toNumber(array);
}

int main(){
  int n;
  scanf("%d", &n);
  do{
    int max = decrease(n);
    int min = increase(n);
    n = max - min;
    printf("%04d - %04d = %04d\n", max, min, n);
  }while(n != 0 && n != 6174);
  return 0;
}