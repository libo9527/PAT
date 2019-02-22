#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

struct Record{
  char id[10];
  int time;
  char status[5];
}all[10010], valide[10010];

bool cmpByIdAndTime(Record r1, Record r2){
  if(strcmp(r1.id, r2.id)){
    return strcmp(r1.id, r2.id) < 0;
  }else{
    return r1.time < r2.time;
  }
}

bool cmpByTime(Record r1, Record r2){
  return r1.time < r2.time;
}

int timeToInt(int hh, int mm, int ss){
  return hh * 3600 + mm * 60 + ss;
}
// 有效记录数
int num = 0;
// 车牌号-》总停留时间
map<string, int> parkTime;
// 最长停车时间
int maxPeriod = -1;
  
int main(){
  int n, k;
  scanf("%d%d", &n, &k);
  for(int i = 0; i < n; i++){
    int hh, mm, ss;
    scanf("%s%d:%d:%d%s", all[i].id, &hh, &mm, &ss, all[i].status);
    all[i].time = timeToInt(hh, mm, ss);
  }
  sort(all, all + n, cmpByIdAndTime);
  // 获取有效记录
  for(int i = 0; i < n - 1; i++){
    if(!strcmp(all[i].status, "in") && !strcmp(all[i + 1].status, "out") && !strcmp(all[i].id, all[i + 1].id)){
      valide[num++] = all[i];
      valide[num++] = all[i + 1];
      int period = all[i + 1].time - all[i].time; 
      if(parkTime.count(all[i].id) == 0){
        parkTime[all[i].id] = 0;
      }
      parkTime[all[i].id] += period;
      maxPeriod = max(maxPeriod, parkTime[all[i].id]);
      i++;
    }
  }
  sort(valide, valide + num, cmpByTime);
  // 当前不超过查询时间的记录下标； 当前车辆数
  int now = 0, count = 0;
  for(int i = 0; i < k; i++){
    int hh, mm, ss;
    scanf("%d:%d:%d", &hh, &mm, &ss);
    int intTime = timeToInt(hh, mm, ss);
    while(now < num && valide[now].time <= intTime){
      if(!strcmp(valide[now].status, "in")){
        count++;
      }else{
        count--;
      }
	  now++;
    }
    printf("%d\n", count);
  }
  map<string, int>::iterator it;
  for(it = parkTime.begin(); it != parkTime.end(); it++){
    if(it->second == maxPeriod){
      printf("%s ", it->first.c_str());
    }
  }
  printf("%02d:%02d:%02d\n", maxPeriod / 3600, maxPeriod % 3600 / 60, maxPeriod % 60);
  return 0;
}