#include <cstdio>

int main(){
  long long a1, a2, a3, b1, b2, b3;
  scanf("%lld.%lld.%lld %lld.%lld.%lld", &a1, &a2, &a3, &b1, &b2, &b3);
  long long temp = a1 * 17 * 29 + a2 * 29 + a3 + b1 * 17 * 29 + b2 * 29 + b3;
  printf("%lld.%lld.%lld", temp / (17 * 29), (temp / 29) % 17, temp % 29);
  return 0;
}