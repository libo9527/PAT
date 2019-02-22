#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 2010;
int toll[24];

struct Record{
  char name[25];
  int mon, dd, hh, mm;
  bool online;
}rec[maxn], temp;

bool cmp(Record r1, Record r2){
  int diff = strcmp(r1.name, r2.name);
  if(diff != 0){
    return diff < 0;
  }else if(r1.dd != r2.dd){
    return r1.dd < r2.dd;
  }else if(r1.hh != r2.hh){
    return r1.hh < r2.hh;
  }else{
    return r1.mm < r2.mm;
  }
}

void calc(int on, int off, int& count, int& money){
  count = 0;
  money = 0;
  temp = rec[on];
  while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm){
    temp.mm++;
    count++;
    money += toll[temp.hh];
    if(temp.mm == 60){
      temp.mm = 0;
      temp.hh++;
    }
    if(temp.hh == 24){
      temp.hh = 0;
      temp.dd++;
    }
  }
}

int main(){
  for(int i = 0; i < 24; i++){
    scanf("%d", &toll[i]);
  }
  int n;
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    char str[10];
    scanf("%s %d:%d:%d:%d %s", rec[i].name, &rec[i].mon, &rec[i].dd, &rec[i].hh, &rec[i].mm, str);
    if(strcmp(str, "on-line") == 0){
      rec[i].online = true;
    }else{
      rec[i].online = false;
    }
  }
  sort(rec, rec + n, cmp);
  int on = 0, off, next;
  while(on < n){
    next = on;
    int isPrint = 0;
    while(next < n && strcmp(rec[next].name, rec[on].name) == 0){
      if(isPrint == 0 && rec[next].online){
        isPrint = 1;
      }else if(isPrint == 1 && !rec[next].online){
        isPrint = 2;
      }
      next++;
    }
    if(isPrint < 2){
      on = next;
      continue;
    }
    int allMoney = 0, money = 0, count = 0; 
	printf("%s %02d\n", rec[on].name, rec[on].mon);
    while(on < next){
      while(on < next - 1 && !(rec[on].online && !rec[on + 1].online)){
        on++;
      }
      off = on + 1;
      if(off == next){
        on = next;
        break;
      }
      calc(on, off, count, money);
      allMoney += money;
      printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", rec[on].dd, rec[on].hh, rec[on].mm, rec[off].dd, rec[off].hh, rec[off].mm, count, money / 100.0);
      on = off + 1;
    }
    printf("Total amount: $%.2f\n", allMoney / 100.0);
  }
  return 0;
}