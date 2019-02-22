#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 100010;
int fullMark[5];
struct Testee{
  int user_id, full_count, grade[5], total_grade;
  bool show;
}testees[maxn], temp;
bool cmp(Testee t1, Testee t2){
  if(t1.total_grade != t2.total_grade){
    return t1.total_grade > t2.total_grade;
  }else if(t1.full_count != t2.full_count){
    return t1.full_count > t2.full_count;
  }else{
    return t1.user_id < t2.user_id;
  }
}

int main(){
  int n, k, m;
  scanf("%d%d%d", &n, &k, &m);
  for(int i = 0; i < k; i++){
    scanf("%d", &fullMark[i]);
  }
  for(int i = 1; i < n + 1; i++){
	testees[i].show = false;
	testees[i].user_id = i;
    fill(testees[i].grade, testees[i].grade + k, -1);
  }
  for(int i = 0; i < m; i++){
    int user_id, problem_id, partial_score_obtained;
    scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
    if(partial_score_obtained != -1){
      testees[user_id].show = true;
    }
	if(partial_score_obtained == -1 && testees[user_id].grade[problem_id - 1] == -1){
	  testees[user_id].grade[problem_id - 1] = 0;
	}
    if(partial_score_obtained == fullMark[problem_id - 1] && testees[user_id].grade[problem_id - 1] < fullMark[problem_id - 1]){
      testees[user_id].full_count++;
    }
    if(partial_score_obtained > testees[user_id].grade[problem_id - 1]){
      testees[user_id].grade[problem_id - 1] = partial_score_obtained;
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 0; j < k; j++){
      if(testees[i].grade[j] > 0){
        testees[i].total_grade += testees[i].grade[j];
      }
    }
  }
  sort(testees + 1, testees + n + 1, cmp);
  int rank = 1;
  for(int i = 1; i <= n; i++){
    if(testees[i].show){
      if(i > 1 && testees[i].total_grade != testees[i - 1].total_grade){
        rank = i;
      }
      printf("%d %05d %d", rank, testees[i].user_id, testees[i].total_grade);
      for(int j = 0; j < k; j++){
       if(testees[i].grade[j] == -1){
         printf(" -");
       }else{
         printf(" %d", testees[i].grade[j]);
       }
      }
      printf("\n");
    }
  }
  return 0;
}