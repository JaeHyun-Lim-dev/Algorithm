// https://www.acmicpc.net/problem/12100
# include <cstdio>

int ans, N;
int arr[20][20];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

void dfs(int cnt) {
	int temp[20][20] = { 0, };
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) {
		arr[i][j] = (arr[i][j] > 0) ? arr[i][j] : -arr[i][j];
		temp[i][j] = arr[i][j];
	}
	if (cnt == 5) {
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ans = (ans > arr[i][j]) ? ans : arr[i][j];
		return;
	}

	for (int k = 0; k < 4; k++) {
		for (int i = (k == 0) ? N - 1 : 0; i >= 0 && i < N; i += (k == 0) ? -1 : 1) {
			for (int j = (k == 2) ? N - 1 : 0; j >= 0 && j < N; j += (k == 2) ? -1 : 1) {
				int x = i, y = j;
				int nx = x + dx[k], ny = y + dy[k];
				while (nx >= 0 && nx < N && ny >= 0 && ny < N) {
					if (arr[nx][ny] != 0) {
						if (arr[x][y] == arr[nx][ny] && arr[x][y] > 0) {
							arr[nx][ny] *= -2;
							arr[x][y] = 0;
						}
						break;
					}
					else {
						arr[nx][ny] = arr[x][y];
						arr[x][y] = 0;
					}
					x += dx[k]; nx += dx[k];
					y += dy[k]; ny += dy[k];
				}
			}
		}
		dfs(cnt + 1);
		for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) arr[i][j] = temp[i][j];
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);
	dfs(0);
	printf("%d\n", ans);
	return 0;
}