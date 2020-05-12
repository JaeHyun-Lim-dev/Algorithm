// https://www.acmicpc.net/problem/1103
# include <cstdio>
using namespace std;

char arr[51][51];
int N, M;
int x, y;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int ans;
int dp[51][51];
bool visited[51][51];

int dfs(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M) return 0;
	if (arr[x][y] == 'H') return 0;
	if (visited[x][y]) { 
		ans = -1;
		return 0;
	}

	int &res = dp[x][y];
	if (res) return res;
	visited[x][y] = 1;
	for (int k = 0; k < 4; k++) {
		int nx, ny, len;
		len = arr[x][y] - '0';
		nx = x + len * dx[k];
		ny = y + len * dy[k];
		int temp = dfs(nx, ny) + 1;
		res = (temp > res) ? temp : res;
		if (ans == -1) return 0;
		else ans = (res > ans) ? res : ans;
	}
	visited[x][y] = 0;
	return res;
}


int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
	}
	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}
