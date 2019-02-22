#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const char ch[5] = "ACME";
int Rank[1000000][5] = {0};
struct Student{
  int id;
  int score[5];
}students[2010];
int row;
bool cmp(Student s1, Student s2){
  return s1.score[row] > s2.score[row];
}

int main(){
  int n, m;
  scanf("%d %d", &n, &m);
  for(int i = 0; i < n; i++){
    scanf("%d %d %d %d", &students[i].id, &students[i].score[1], &students[i].score[2], &students[i].score[3]);
    students[i].score[0] = (students[i].score[1] + students[i].score[2] + students[i].score[3]) / 3;
  }
  for(int j = 0; j < 4; j++){
    row = j;
    sort(students, students + n, cmp);
    Rank[students[0].id][j] = 1;
    for(int k = 1; k < n; k++){
      if(students[k].score[j] == students[k - 1].score[j]){
        Rank[students[k].id][j] = Rank[students[k - 1].id][j]; 
      }else{
        Rank[students[k].id][j] = k + 1; 
      }
    }
  }
  for(int p = 0; p < m; p++){
    int checkId;
    scanf("%d", &checkId);
    if(Rank[checkId][0] == 0){
      printf("N/A\n");
    }else{
      int idx = 0;
      for(int q = 1; q < 4; q++){
        if(Rank[checkId][q] < Rank[checkId][idx]){
          idx = q; 
        }
      }
      printf("%d %c\n", Rank[checkId][idx], ch[idx]);
    }
  }
  return 0;
}