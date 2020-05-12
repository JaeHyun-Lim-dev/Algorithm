// https://www.acmicpc.net/problem/14500
# include <cstdio>

int N, M;
int arr[500][500], visited[500][500];
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int ans = 0, i, j;

void dfs(int tx, int ty, int cnt, int sum) {
	if (cnt == 4) {
		ans = (ans < sum) ? sum : ans;
		return;
	}
	for (int k = 0; k < 4; k++) {
		int x = tx + dx[k], y = ty + dy[k];
		if (x < 0 || y < 0 || x >= N || y >= M || visited[x][y] || x < i) continue;
		visited[x][y] = 1;
		dfs(x, y, cnt + 1, sum + arr[x][y]);
		visited[x][y] = 0;
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int n = 0; n < N; n++) for (int m = 0; m < M; m++) scanf("%d", &arr[n][m]);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			visited[i][j] = 1;
			dfs(i, j, 1, arr[i][j]);
			visited[i][j] = 0;
			int sum = arr[i][j]; // block ¤¿
			int min = 1000, cnt = 0;
			for (int k = 0; k < 4; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x < 0 || y < 0 || x >= N || y >= M) continue;
				sum += arr[x][y]; cnt++;
				min = (min > arr[x][y]) ? arr[x][y] : min;
			}
			if (cnt == 4) sum -= min;
			ans = (ans < sum) ? sum : ans;
		}
	}
	printf("%d", ans);
	return 0;
}