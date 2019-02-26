#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

const int maxn = 110;

struct Fraction{
  ll up, down;
}ans, temp;

ll gcd(ll a, ll b){
  if(b == 0){
    return a;
  }else {
    return gcd(b, a % b);
  }
}

Fraction reduction(Fraction f){
  if(f.down < 0){
    f.up = -f.up;
    f.down = -f.down;
  }
  if(f.up == 0){
    f.down = 1;
  }else{
    ll d = gcd(abs(f.up), abs(f.down));
    f.up /= d;
    f.down /= d;
  }
  return f;
}

Fraction add(Fraction f1, Fraction f2){
  Fraction ret;
  ret.up = f1.up * f2.down + f2.up * f1.down;
  ret.down = f1.down * f2.down;
  return reduction(ret);
}

void show(Fraction f){
  if(f.down == 1){
    printf("%lld", f.up);
  }else if(f.up > f.down){
    printf("%lld %lld/%lld", f.up / f.down, abs(f.up) % f.down, f.down);
  }else{
    printf("%lld/%lld", f.up, f.down);
  }
}

int main(){
  int n;
  scanf("%d", &n);
  ans.up = 0;
  ans.down = 1;
  for(int i = 0; i < n; i++){
    scanf("%lld/%lld", &temp.up, &temp.down);
    ans = add(ans, temp);
  }
  show(ans);
  return 0;
}