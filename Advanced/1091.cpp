#include <cstdio>
#include <queue>
using namespace std;


struct Node {
	int x, y, z;
} node;

int matrix[1290][130][65];
bool inq[1290][130][65];
int X[6] = {0, 0, 0, 0, 1, -1};
int Y[6] = {0, 0, 1, -1, 0, 0};
int Z[6] = {1, -1, 0, 0, 0, 0};

int m, n, l, t;


bool check(int x, int y, int z) {
	if(x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) {
		return false;
	}
	if(matrix[x][y][z] == 0 || inq[x][y][z] == true) {
		return false;
	}
	return true;
}

int bfs(int x, int y, int z) {
	queue<Node> q;
	int count = 0;
	node.x = x;
	node.y = y;
	node.z = z;
	q.push(node);
	inq[x][y][z] = true;
	while(!q.empty()) {
		Node front = q.front();
		q.pop();
		count++;
		for(int i = 0; i < 6; i++) {
			int x = front.x + X[i];
			int y = front.y + Y[i];
			int z = front.z + Z[i];
			if(check(x, y, z)) {
				node.x = x;
				node.y = y;
				node.z = z;
				q.push(node);
				inq[x][y][z] = true;
			}
		}
	}
	if(count < t) {
		return 0;
	} else {
		return count;
	}
}

int main() {
	int ans = 0;
	scanf("%d%d%d%d", &m, &n, &l, &t);
	for(int z = 0; z < l; z++) {
		for(int x = 0; x < m; x++) {
			for(int y = 0; y < n; y++) {
				scanf("%d", &matrix[x][y][z]);
			}
		}
	}
	for(int z = 0; z < l; z++) {
		for(int x = 0; x < m; x++) {
			for(int y = 0; y < n; y++) {
				if(matrix[x][y][z] == 1 && inq[x][y][z] == false) {
					ans += bfs(x, y, z);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}