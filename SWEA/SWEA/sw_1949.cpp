# include <cstdio>

int T, N, K, H, ans;
int arr[8][8], visited[8][8];
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

void dfs(int x, int y, int did, int cnt, int th) {
	ans = (cnt > ans) ? cnt : ans;
	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k], ny = y + dy[k];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny]) continue;
		if (th <= arr[nx][ny]) {
			if (did) continue;
			if (arr[nx][ny] - th >= K) continue;
			visited[nx][ny] = 1;
			dfs(nx, ny, 1, cnt + 1, th - 1);
			visited[nx][ny] = 0;
		}
		else {
			visited[nx][ny] = 1;
			dfs(nx, ny, did, cnt + 1, arr[nx][ny]); 
			visited[nx][ny] = 0;
		}
	}
	return;
}

int main() {
	scanf("%d", &T);
	for (int t_c = 1; t_c <= T; t_c++) {
		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);
		H = ans = 0;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) H = (arr[i][j] > H) ? arr[i][j] : H;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (arr[i][j] == H) {
					visited[i][j] = 1;
					dfs(i, j, 0, 1, arr[i][j]); 
					visited[i][j] = 0;
				}
			}
		}
		printf("#%d %d\n", t_c, ans);
	}
	return 0;
}