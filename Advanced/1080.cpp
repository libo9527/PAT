#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 40010, maxm = 110, maxk = 10;
struct Application{
  int id, ge, gi, total, rank;
  int choices[maxk];
}applications[maxn];

struct Shool{
  int quota, appIdx[maxn], num, last;
}shools[maxm];

bool cmpG(Application a1, Application a2){
  if(a1.total != a2.total){
    return a1.total > a2.total;
  }else {
    return a1.ge > a2.ge;
  }
}

bool cmpID(int a, int b){
  return applications[a].id < applications[b].id;
}

int main(){
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for(int i = 0; i < m; i++){
    scanf("%d", &shools[i].quota);
    shools[i].last = -1;
  }
  for(int i = 0; i < n; i++){
    scanf("%d%d", &applications[i].ge, &applications[i].gi);
	applications[i].id = i;
    applications[i].total = applications[i].ge + applications[i].gi;
    for(int j = 0; j < k; j++){
      scanf("%d", &applications[i].choices[j]);
    }
  }
  sort(applications, applications + n, cmpG);
  for(int i = 0; i < n; i++){
    if(i > 0 && applications[i].total == applications[i - 1].total && applications[i].ge == applications[i - 1].ge){
      applications[i].rank = applications[i - 1].rank;
    }else{
      applications[i].rank = i + 1;
    }
  }
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      int sid = applications[i].choices[j];
      if(shools[sid].num < shools[sid].quota || (shools[sid].last != -1 && applications[i].rank == applications[shools[sid].last].rank)){
        shools[sid].appIdx[shools[sid].num] = i;
        shools[sid].num++;
        shools[sid].last = i;
        break;
      }
    }
  }
  for(int i = 0; i < m; i++){
    sort(shools[i].appIdx, shools[i].appIdx + shools[i].num, cmpID);
    for(int j = 0; j < shools[i].num; j++){
      printf("%d", applications[shools[i].appIdx[j]].id);
      if(j < shools[i].num - 1){
        printf(" ");
      }
    }
    printf("\n");
  }
  return 0;
}