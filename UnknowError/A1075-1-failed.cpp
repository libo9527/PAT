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
	testees[i].full_count = 0;
	testees[i].total_grade = 0;
    fill(testees[i].grade, testees[i].grade + k, -1);
  }
  for(int i = 0; i < m; i++){
    int user_id, problem_id, partial_score_obtained;
    scanf("%d%d%d", &user_id, &problem_id, &partial_score_obtained);
    if(partial_score_obtained == -1){
      testees[user_id].grade[problem_id - 1] = 0;
    }
    if(partial_score_obtained > testees[user_id].grade[problem_id - 1]){
	  testees[user_id].show = true;
      testees[user_id].user_id = user_id;
  	  if(testees[user_id].grade[problem_id - 1] == -1){
  		  testees[user_id].total_grade = testees[user_id].total_grade + partial_score_obtained;
  	  }else{
  		  testees[user_id].total_grade = testees[user_id].total_grade - testees[user_id].grade[problem_id - 1] + partial_score_obtained;
  	  }
  	  testees[user_id].grade[problem_id - 1] = partial_score_obtained;
      if(partial_score_obtained == fullMark[problem_id - 1]){
        testees[user_id].full_count++;
      }
    }
  }
  sort(testees + 1, testees + n + 1, cmp);
  int rank = 1;
  printf("1 %05d %d ", testees[1].user_id, testees[1].total_grade);
  for(int i = 0; i < k; i++){
    if(testees[1].grade[i] == -1){
      printf("-");
    }else{
      printf("%d", testees[1].grade[i]);  
    }
    if(i == k - 1){
      printf("\n");
    }else{
      printf(" ");
    }
  }
  for(int i = 2; i < n + 1; i++){
    if(testees[i].show){
      if(testees[i].total_grade == testees[i - 1].total_grade){
        printf("%d %05d %d ", rank, testees[i].user_id, testees[i].total_grade);
      }else{
        rank = i;
        printf("%d %05d %d ", i, testees[i].user_id, testees[i].total_grade);
      }
      for(int j = 0; j < k; j++){
        if(testees[i].grade[j] == -1){
          printf("-");
        }else{
          printf("%d", testees[i].grade[j]);  
        }
        if(j == k - 1){
          printf("\n");
        }else{
          printf(" ");
        }
      }
    }
  }
  return 0;
}