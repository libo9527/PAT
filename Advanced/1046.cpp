#include <cstdio>

int main(){
  int n;
  scanf("%d", &n);
  int dist[n+1], sum = 0; 
  for(int i = 1; i <= n; i++){
    int temp;
    scanf("%d", &temp);
    sum += temp;
    dist[i] = sum;
  }
  int k, n1, n2;
  scanf("%d", &k);
  int distance;
  for(int i = 0; i < k; i++){
    int left, right;
    scanf("%d%d", &left, &right);
    if(left > right){
      int temp = left;
      left = right;
      right = temp;
    }
    distance = dist[right-1] - dist[left-1];
    if(sum - distance < distance){
		printf("%d\n", sum - distance);
    }else{
		printf("%d\n", distance);
	}
  }
  return 0;
}