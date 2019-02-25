#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2){
  return s1 + s2 < s2 + s1;
}

int main(){
  int n;
  cin >> n;
  string seg[10010], ans;
  for(int i = 0; i < n; i++){
    cin >> seg[i];
  }
  sort(seg, seg + n, cmp);
  for(int i = 0; i < n; i++){
    ans += seg[i];
  }
  while(ans.length() != 0 && ans[0] == '0'){
    ans.erase(ans.begin());
  }
  if(ans.length() == 0){
    cout << 0;
  }else{
    cout << ans;
  }
  return 0;
}