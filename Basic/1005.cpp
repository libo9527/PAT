#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
  return a > b;
}

int main(){
  int n, test[111], ans[111], hashtable[111] = {0};
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int temp;
    scanf("%d", &temp);
    test[i] = temp;
    while(temp != 1){
      if(temp <= 100) hashtable[temp]++;
      if(temp % 2 == 0){
        temp /= 2;
      }else {
        temp = (3 * temp + 1) / 2;
      }
    }
  }
  int num = 0;
  for(int i = 0; i < n; i++){
    if(hashtable[test[i]] == 1){
      ans[num++] = test[i];
    }
  }
  sort(ans, ans + num, cmp);
  for(int i = 0; i < num; i++){
    printf("%d", ans[i]);
    if(i < num - 1){
      printf(" ");
    }
  }
  return 0;
}