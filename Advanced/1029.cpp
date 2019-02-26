// 由于18年3月份之后PAT对此题进行了内存溢出的强化样例
// 故《算法笔记》中的题解将出现“内存超限”的错误
// 参考柳神的题解 https://www.liuchuo.net/archives/2248
// 修改后可AC
#include <cstdio>
#include <algorithm>
using namespace std;

const int INF = (1 << 31) - 1;
const int maxn = 200010;

int main() {
	int n1, n2, i, j, count = 0;
	int seq1[maxn], seq2;
	scanf("%d", &n1);
	for(i = 0; i < n1; i++) {
		scanf("%d", &seq1[i]);
	}
	seq1[n1] = INF;
	scanf("%d", &n2);
	scanf("%d", &seq2);
	int pos = (n1 + n2 - 1) / 2;
	i = j = 0;
	while(count < pos) {
		if(seq1[i] <= seq2) {
			i++;
			count++;
		} else {
			j++;
			if(j < n2) {
				scanf("%d", &seq2);
			} else {
				seq2 = INF;
			}
			count++;
		}
	}
	printf("%d", min(seq1[i], seq2));
	return 0;
}