#include <cstdio>

struct Student{
  char name[15];
  char id[15];
  int score;
}temp, min, max;

int main(){
  int n;
  scanf("%d", &n);
  min.score = 101;
  max.score = -1;
  for(int i = 0; i < n; i++){
    scanf("%s%s%d", temp.name, temp.id, &temp.score);
    if(temp.score < min.score)min = temp;
    if(temp.score > max.score)max = temp;
  }
  printf("%s %s\n", max.name, max.id);
  printf("%s %s\n", min.name, min.id);
  return 0;
}