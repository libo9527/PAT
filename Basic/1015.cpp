#include <cstdio>
#include <algorithm>
using namespace std;

struct People{
  int ID_Number, Virtue_Grade, Talent_Grade, Total_Grade, rank;
}peoples[100010];
void swap(People peoples[], int i, int j){
  People temp = peoples[i];
  peoples[i] = peoples[j];
  peoples[j] = temp;
}
bool cmp(People p1, People p2){
  if(p1.rank != p2.rank){
    return p1.rank < p2.rank;
  }else {
    if(p1.Total_Grade != p2.Total_Grade){
      return p1.Total_Grade > p2.Total_Grade;
    }else {
      if(p1.Virtue_Grade != p2.Virtue_Grade){
        return p1.Virtue_Grade > p2.Virtue_Grade;
      }else{
        return p1.ID_Number < p2.ID_Number;
      }
    }
  }
}

int main(){
  int N, L, H, num = 0;
  scanf("%d %d %d", &N, &L, &H);
  for(int i = 0; i < N; i++){
    People temp;
    scanf("%d %d %d", &temp.ID_Number, &temp.Virtue_Grade, &temp.Talent_Grade);
    temp.Total_Grade = temp.Virtue_Grade + temp.Talent_Grade;
    if(temp.Virtue_Grade >= L && temp.Talent_Grade >= L){
      if(temp.Virtue_Grade >= H && temp.Talent_Grade >= H){
        temp.rank = 1;
      }else if(temp.Virtue_Grade >= H){
        temp.rank = 2;
      }else if(temp.Virtue_Grade >= temp.Talent_Grade){
        temp.rank = 3;
      }else{
        temp.rank = 4;
      }
      peoples[num++] = temp;
    }
  }
  sort(peoples, peoples+num, cmp);
  printf("%d\n", num);
  for(int k = 0; k < num; k++){
    printf("%d %d %d\n", peoples[k].ID_Number, peoples[k].Virtue_Grade, peoples[k].Talent_Grade);
  }
  return 0;
}