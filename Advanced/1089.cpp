#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 111;
bool isSame(int prime[], int now[], int n){
  for(int i = 0; i < n; i++){
    if(prime[i] != now[i]){
      return false;
    }
  }
  return true;
}

int n, num1[maxn], num2[maxn], num3[maxn];
int main(){
  bool flag = false; // 是否是当前排序方法 
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%d", &num1[i]);
    num3[i] = num1[i];
  }
  for(int i = 0; i < n; i++){
    scanf("%d", &num2[i]);
  }
  for(int i = 1; i < n; i++){
    for(int j = i - 1; j >= 0; j--){
      if(num3[j + 1] < num3[j]){
        swap(num3[j + 1], num3[j]);
      }else{
        break;
      }
    }
    if(flag){
      for(int k = 0; k < n; k++){
        printf("%d", num3[k]);
        if(k < n - 1){
          printf(" ");
        }
      }
      return 0;
    }
    if(isSame(num2, num3, n)){
      printf("Insertion Sort\n");
      flag = true;
    }
  }
  for(int i = 0; i < n; i++){
    num3[i] = num1[i];
  }
  for(int step = 2; step / 2 <= n; step *= 2){
    for(int i = 0; i < n; i += step){
      sort(num3 + i, num3 + min(i + step, n));
    }
    if(flag){
      for(int k = 0; k < n; k++){
        printf("%d", num3[k]);
        if(k < n - 1){
          printf(" ");
        }
      }
      return 0;
    }
    if(isSame(num2, num3, n)){
      printf("Merge Sort\n");
      flag = true;
    }
  }
  return 0;
}