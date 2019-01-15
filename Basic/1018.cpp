#include <cstdio>

int change(char c){
  if (c == 'B'){
    return 0;
  }else if(c == 'C'){
    return 1;
  }else {
    return 2;
  }
}

int main(){
  int n;
  scanf("%d", &n);
  char mp[3] = {'B','C','J'};
  char c1, c2;
  int a1, a2;
  int succA[3] = {0}, succB[3] = {0};
  int countA[3] = {0}, countB[3] = {0};
  for(int i = 0; i < n; i++){
    getchar();
    scanf("%c %c", &c1, &c2);
    a1 = change(c1);
    a2 = change(c2);
    if((a1+1)%3 == a2){ // 甲赢
      succA[0]++;
      succB[2]++;
      countA[a1]++;
    }else if ((a2+1)%3 == a1){
      succB[0]++;
      succA[2]++;
      countB[a2]++;
    }else{
      succA[1]++;
      succB[1]++;
    }
  }
  printf("%d %d %d\n", succA[0], succA[1], succA[2]);
  printf("%d %d %d\n", succB[0], succB[1], succB[2]);
  int idx1, idx2;
  int max1 = 0, max2 = 0;
  for(int i = 0; i < 3; i++){
    if(countA[i] > max1){
      max1 = countA[i];
      idx1 = i;
    }
    if(countB[i] > max2){
      max2 = countB[i];
      idx2 = i;
    }
  }
  printf("%c %c\n", mp[idx1], mp[idx2]);
  return 0;
}