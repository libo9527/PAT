#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 35;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int n;
int pre[maxn], in[maxn];

Node* create(int preL, int preR, int inL, int inR) {
	if(preL > preR) {
		return NULL;
	}
	Node* root = new Node;
	root->data = pre[preL];
	int k;
	for(k = inL; k <= inR; k++) {
		if(in[k] == root->data) {
			break;
		}
	}
	int numL = k - inL;
	root->left = create(preL + 1, preL + numL, inL, k - 1);
	root->right = create(preL + numL + 1, preR, k + 1, inR);
	return root;
}

int num = 0;
void postR(Node* root) {
	if(root == NULL) {
		return;
	}
	postR(root->left);
	postR(root->right);
	printf("%d", root->data);
	num++;
	if(num < n) {
		printf(" ");
	}
}

int main() {
	scanf("%d", &n);
	char str[5];
	stack<int> s;
	int data, indexP = 0, indexI = 0;
	for(int i = 0; i < 2 * n; i++) {
		scanf("%s", str);
		if(strcmp(str, "Push") == 0) {
			scanf("%d", &data);
			pre[indexP++] = data;
			s.push(data);
		} else {
			data = s.top();
			in[indexI++] = data;
			s.pop();
		}
	}
	Node* root = create(0, indexP - 1, 0, indexI - 1);
	postR(root);
	return 0;
}