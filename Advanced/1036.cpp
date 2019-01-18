#include <cstdio>

struct Student{
  char name[15];
  char sex;
  char id[15];
  int grade;
}temp, male, female;

void init(){
  male.sex = 'M';
  female.sex = 'F';
  male.grade = 101;
  female.grade = -1;
}

int main(){
  init();
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++){
    scanf("%s %c %s %d", temp.name, &temp.sex, temp.id, &temp.grade);
    if(temp.sex == male.sex && temp.grade < male.grade) male = temp;
    if(temp.sex == female.sex && temp.grade > female.grade) female = temp;
  }
  if (female.grade == -1) printf("Absent\n");
  else printf("%s %s\n", female.name, female.id);
  if (male.grade == 101) printf("Absent\n");
  else printf("%s %s\n", male.name, male.id);
  if(female.grade == -1 || male.grade == 101) printf("NA\n");
  else printf("%d\n", female.grade - male.grade);
  return 0;
}