#include <cstdio>

struct Student{
  long long cardId;
  int tryId;
  int trueId;
} students[1010];

int main(){
  int n, m;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    getchar();
    scanf("%lld%d%d", &students[i].cardId, &students[i].tryId, &students[i].trueId);
  }
  scanf("%d", &m);
  int temp;
  for(int i = 0; i < m; i++){
    scanf("%d", &temp);
    for(int j = 0; j < n; j++){
      if(temp == students[j].tryId){
        printf("%lld %d\n", students[j].cardId, students[j].trueId);
      }
    }
  }
  return 0;
}