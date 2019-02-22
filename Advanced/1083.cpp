#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100000;
struct Student{
  char name[15], id[15];
  int grade;
}students[maxn], temp;

int main(){
  for(int i = 0; i < maxn; i++){
    students[i].grade = -1;
  }
  int n, min, max;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    scanf("%s%s%d", temp.name, temp.id, &temp.grade);
    students[temp.grade] = temp;
  }
  scanf("%d%d", &min, &max);
  bool flag = false;
  for(int i = maxn - 1; i >= 0; i--){
    if(students[i].grade >= min && students[i].grade <= max){
      printf("%s %s\n", students[i].name, students[i].id);
      flag = true;
    }
  }
  if(!flag){
    printf("NONE\n");
  }
  return 0;
}