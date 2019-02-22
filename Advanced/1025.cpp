#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 30010;
const int maxa = 110;

struct Testee{
  char registration_number[15];
  int score, final_rank, location_number, local_rank;
}testees[maxn];

bool cmp(Testee t1, Testee t2){
  if(t1.score != t2.score){
    return t1.score > t2.score;
  }else{
    return strcmp(t1.registration_number, t2.registration_number) < 0;
  }
}

int main(){
  int n, num = 0, nowNum, location_num = 1;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int k;
	nowNum = 0;
    scanf("%d", &k); 
    for(int j = 0; j < k; j++){
      scanf("%s%d", testees[num + nowNum].registration_number, &testees[num + nowNum].score);
      testees[num + nowNum].location_number = location_num;
      nowNum++;
    }
    location_num++;
    sort(testees + num, testees + num + nowNum, cmp);
    testees[num].local_rank = 1;
    for(int j = num + 1; j < num + nowNum; j++){
      if(testees[j].score == testees[j - 1].score){
        testees[j].local_rank = testees[j - 1].local_rank;
      }else{
        testees[j].local_rank = j - num + 1;
      }
    }
    num += nowNum;
  }
  sort(testees, testees + num, cmp);
  testees[0].final_rank = 1;
  printf("%d\n", num);
  printf("%s %d %d %d\n", testees[0].registration_number, testees[0].final_rank, testees[0].location_number, testees[0].local_rank);
  for(int i = 1; i < num; i++){
    if(testees[i].score == testees[i - 1].score){
      testees[i].final_rank = testees[i - 1].final_rank;
    }else{
      testees[i].final_rank = i + 1;
    }
    printf("%s %d %d %d\n", testees[i].registration_number, testees[i].final_rank, testees[i].location_number, testees[i].local_rank);
  }
  return 0;
}