#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct People{
  char name[10];
  int age, worth;
}peoples[maxn];

bool cmp(People p1, People p2){
  if(p1.worth != p2.worth){
    return p1.worth > p2.worth;
  }else if(p1.age != p2.age){
    return p1.age < p2.age;
  }else{
    return strcmp(p1.name, p2.name) < 0;
  }
}

int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    scanf("%s %d %d", peoples[i].name, &peoples[i].age, &peoples[i].worth);
  }
  sort(peoples, peoples + n, cmp);
  for(int i = 0; i < k; i++){
    printf("Case #%d:\n", i + 1);
    int m, amin, amax, num = 0;
    bool flag = false;
    scanf("%d %d %d", &m, &amin, &amax);
    for(int j = 0; j < n; j++){
      if(num < m && peoples[j].age >= amin && peoples[j].age <= amax){
        printf("%s %d %d\n", peoples[j].name, peoples[j].age, peoples[j].worth);
        flag = true;
		num++;
      }
    }
    if(!flag){
      printf("None\n");
    }
  }
  return 0;
}