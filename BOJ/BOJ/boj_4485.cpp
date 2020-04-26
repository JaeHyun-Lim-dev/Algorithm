# include <cstdio>
# include <queue>
using namespace std;

int n, arr[125][125];
int ck[125][125];
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };
int T;
struct ST {
	int x, y, z;
};

bool operator <(ST x, ST y) {
	return x.z > y.z;
}

int main() {
	while (scanf("%d", &n)) {
		T++;
		priority_queue<ST> pq;
		if (n == 0) return 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) scanf("%d", &arr[i][j]);
		pq.push({ 0, 0, arr[0][0] });
		ck[0][0] = T;
		while (!pq.empty()) {
			ST t = pq.top();
			pq.pop();
			if (t.x == n - 1 && t.y == n - 1) {
				printf("Problem %d: %d\n", T, t.z);
				break;
			}
			for (int i = 0; i < 4; i++) {
				int x = t.x + dx[i];
				int y = t.y + dy[i];
				if (x < 0 || y < 0 || x >= n || y >= n || ck[x][y] == T) continue;
				ck[x][y] = T;
				pq.push({ x,y,t.z + arr[x][y] });
			}
		}
	}
	return 0;
}