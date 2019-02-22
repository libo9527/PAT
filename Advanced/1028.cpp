#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 100010;
struct Student{
  int id, grade;
  char name[10];
}students[maxn];

bool cmp1(Student s1, Student s2){
  return s1.id < s2.id;
}

bool cmp2(Student s1, Student s2){
  if(strcmp(s1.name, s2.name) != 0){
    return strcmp(s1.name, s2.name) < 0;
  }else{
    return s1.id < s2.id;
  }
}

bool cmp3(Student s1, Student s2){
  if(s1.grade != s2.grade){
    return s1.grade < s2.grade;
  }else{
    return s1.id < s2.id;
  }
}

int main(){
  int n, c, num = 0;
  scanf("%d%d", &n, &c);
  for(int i = 0; i < n; i++){
    scanf("%d %s %d", &students[i].id, students[i].name, &students[i].grade);
  }
  if(c == 1){
    sort(students, students + n, cmp1);
  }else if (c == 2){
    sort(students, students + n, cmp2);
  }else {
    sort(students, students + n, cmp3);
  }
  for(int i = 0; i < n; i++){
    printf("%06d %s %d\n", students[i].id, students[i].name, students[i].grade);
  }
  return 0;
}