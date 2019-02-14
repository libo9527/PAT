#include <cstdio>
struct Money{
  int galleon;
  int sickle;
  int knut;
} a, b;

int main(){
  scanf("%d.%d.%d %d.%d.%d", &a.galleon, &a.sickle, &a.knut, &b.galleon, &b.sickle, &b.knut);
  Money ans;
  int temp = b.galleon * 17 * 29 + b.sickle * 29 + b.knut - (a.galleon * 17 * 29 + a.sickle * 29 + a.knut);
  if(temp < 0){
    printf("-");
    temp = -temp;
  }
  printf("%d.%d.%d", temp / (29 * 17), (temp % (29 * 17)) / 29, temp % 29);
  return 0;
}