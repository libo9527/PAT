#include <cstdio>
#include <algorithm>
using namespace std;

struct Mooncake{
  double totalAmount;
  double totalProfit;
  double singleProfit;
  int soaledAmount;
}mooncakes[1010];

bool cmp(Mooncake m1, Mooncake m2){
  return m1.singleProfit > m2.singleProfit;
}

int main(){
  int n;
  double d;
  scanf("%d%lf", &n, &d);
  for(int i = 0; i < n; i++){
    scanf("%lf", &mooncakes[i].totalAmount);
  }
  for(int i = 0; i < n; i++){
    scanf("%lf", &mooncakes[i].totalProfit);
    mooncakes[i].singleProfit = mooncakes[i].totalProfit / mooncakes[i].totalAmount;
    mooncakes[i].soaledAmount = 0;
  }
  sort(mooncakes, mooncakes + n, cmp);
  double ans = 0;
  for(int i = 0; i < n; i++){
    if(d >= mooncakes[i].totalAmount){
      ans += mooncakes[i].totalProfit;
      d -= mooncakes[i].totalAmount;
    }else{
      ans += mooncakes[i].singleProfit * d;
      break;
    }
  }
  printf("%.2f", ans);
  return 0;
}