# include <cstdio>

int N, T, sx, sy, ans, arr[21][21], dessert[101], visited[21][21];
int dx[4] = { 1, -1, -1, 1 }, dy[4] = { 1, 1, -1, -1 };

void dfs(int i, int j, int cnt, int dir) {
	if (cnt > 0 && i == sx && j == sy) {
		ans = (cnt > ans) ? cnt : ans;
		return;
	}
	for (int k = dir; k < dir + 2 && k < 4; k++) {
		int x = i + dx[k], y = j + dy[k];
		if (x < 0 || x >= N || y < 0 || y >= N || dessert[arr[x][y]] || visited[x][y]) continue;
		dessert[arr[x][y]] = 1;
		visited[x][y] = 1;
		dfs(x, y, cnt + 1, k);
		visited[x][y] = 0;
		dessert[arr[x][y]] = 0;
	}
}

int main() {
	scanf("%d", &T);
	for (int t_c = 1; t_c <= T; t_c++) {
		scanf("%d", &N);
		ans = -1;
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);
		for (int i = 0; i < N - 1; i++) { 
			for (int j = 0; j < N - 1; j++) {
				sx = i; sy = j;
				dfs(i, j, 0, 0); 
			}
		}
		printf("#%d %d\n", t_c, ans);
	}
	return 0;
}