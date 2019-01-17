#include <cstdio>

struct People{
  char name[10];
  int y, m, d;
}temp, max, min, old, young;

void init(){
  max.y = young.y = 1814;
  min.y = old.y = 2014;
  max.m = min.m = old.m = young.m = 9;
  max.d = min.d = old.d = young.d = 6;
}

bool older(People a, People b){
   if(a.y != b.y) return a.y <= b.y;
   else if (a.m != b.m) return a.m <= b.m;
   else return a.d <= b.d;
}

bool younger(People a, People b){
   if(a.y != b.y) return a.y >= b.y;
   else if (a.m != b.m) return a.m >= b.m;
   else return a.d >= b.d;
}

int main(){
  init();
  int n, count = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%s %d/%d/%d", temp.name, &temp.y, &temp.m, &temp.d);
    if(older(temp, min) && younger(temp, max)){
      count++;
      if(older(temp, old)) old = temp;
      if(younger(temp, young)) young = temp;
    }
  }
  if(count == 0) printf("0");
  else printf("%d %s %s", count, old.name, young.name);
  return 0;
}