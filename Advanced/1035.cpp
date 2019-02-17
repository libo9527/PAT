#include <cstdio>
#include <cstring>
struct Account{
  char username[15];
  char password[15];
}users[1010];

int main(){
  int n;
  scanf("%d", &n);
  int num = 0, ans[1010];
  for(int i = 0; i < n; i++){
    scanf("%s %s", users[i].username, users[i].password);
    int len = strlen(users[i].password);
    for(int j = 0; j < len; j++){
      if(users[i].password[j] == '1' || users[i].password[j] == 'l' || users[i].password[j] == '0' || users[i].password[j] == 'O'){
        ans[num++] = i;
        break;
      }
    }
  }
  if(num == 0){
    if(n == 1){
      printf("There is 1 account and no account is modified\n");
      return 0;
    }else{
      printf("There are %d accounts and no account is modified\n", n);
      return 0;
    }
  }
  printf("%d\n", num);
  for(int k = 0; k < num; k++){
    printf("%s ", users[ans[k]].username);
    int len = strlen(users[ans[k]].password);
    for(int j = 0; j < len; j++){
      if(users[ans[k]].password[j] == '1'){
        printf("@");
      }else if(users[ans[k]].password[j] == 'l'){
        printf("L");
      }else if(users[ans[k]].password[j] == '0'){
        printf("%%");
      }else if(users[ans[k]].password[j] == 'O'){
        printf("o");
      }else{
        printf("%c", users[ans[k]].password[j]);
      }
    }
    printf("\n");
  }
  return 0;
}