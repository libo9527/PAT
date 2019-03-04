#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 35;

struct Node {
	int data;
	Node* left;
	Node* right;
};

int post[maxn];
int in[maxn];
int n;

Node* create(int postL, int postR, int inL, int inR) {
	if(postL > postR) {
		return NULL;
	}
	Node* root = new Node;
	root->data = post[postR];
	int k;
	for(int i = inL; i <= inR; i++) {
		if(in[i] == root->data) {
			k = i;
			break;
		}
	}
	int lenL = k - inL;
	root->left = create(postL, postL + lenL - 1, inL, k - 1);
	root->right = create(postL + lenL, postR - 1, k + 1, inR);
	return root;
}

int num = 0;
void levelR(Node* root) {
	queue<Node*> q;
	q.push(root);
	while(!q.empty()) {
		Node* top = q.front();
		q.pop();
		num++;
		printf("%d", top->data);
		if(num < n) {
			printf(" ");
		}
		if(top->left != NULL) {
			q.push(top->left);
		}
		if(top->right != NULL) {
			q.push(top->right);
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &post[i]);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
	}
	Node* root = create(0, n - 1, 0, n - 1);
	levelR(root);
	return 0;
}