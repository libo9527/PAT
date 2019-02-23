#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
  return a < b;
}

int main(){
  int n, m, coins[100010], count[1010] = {0};
  scanf("%d%d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d", &coins[i]);
    count[coins[i]]++;
  }
  sort(coins, coins + n, cmp);
  int flag = true;
  for(int i = 0; i < n; i++){
    if(coins[i] != m - coins[i] && count[coins[i]] > 0 && count[m - coins[i]] > 0){
      printf("%d %d", coins[i], m - coins[i]);
      flag = false;
      break;
    }
    if(coins[i] == m - coins[i] && count[coins[i]] > 1){
      printf("%d %d", coins[i], coins[i]);
      flag = false;
      break;
    }
  }
  if(flag){
    printf("No Solution");
  }
  return 0;
}