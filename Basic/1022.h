#include <cstdio>

int main(){
 int a, b, d;
 scanf("%d%d%d", &a, &b, &d);
 int sum = a + b, num = 0;
 int ans[31];
 do{
   ans[num++] = sum % d;
   sum /= d;
 }while(sum != 0);
 for(int i = num - 1; i >= 0; i--){
   printf("%d", ans[i]);
 }
  return 0;
}