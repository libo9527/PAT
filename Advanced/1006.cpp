#include <cstdio>

struct Student{
  char name[20];
  int h1, h2, m1, m2, s1, s2;
}temp, first, last;

bool pre(Student a, Student b){
  if(a.h1 != b.h1) return a.h1 < b.h1;
  else if(a.m1 != b.m1) return a.m1 < b.m1;
  else return a.s1 < b.s1;
}

bool later(Student a, Student b){
  if(a.h2 != b.h2) return a.h2 > b.h2;
  else if(a.m2 != b.m2) return a.m2 > b.m2;
  else return a.s2 > b.s2;
}

void init(){
  first.h1 = 24;
  first.m1 = first.s1 = 0;
  last.h2 = 0;
  last.m2 = last.m2 = 0;
}

int main(){
  init();
  int m;
  scanf("%d", &m);
  for(int i = 0; i < m; i++){
    scanf("%s %d:%d:%d %d:%d:%d", temp.name, &temp.h1, &temp.m1, &temp.s1, &temp.h2, &temp.m2, &temp.s2);
    if(pre(temp, first)) first = temp;
    if(later(temp, last)) last = temp;
  }
  printf("%s %s", first.name, last.name);
  return 0;
}