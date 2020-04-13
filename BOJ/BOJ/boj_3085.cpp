// https://www.acmicpc.net/problem/3085
# include <cstdio>

char arr[51][51];
int N, dx[2] = { 1, 0 }, dy[2] = { 0, 1 }, ans;

void check() {
	for (int i = 0; i < N; i++) {
		int temp = 1;
		for (int j = 1; j < N; j++) {
			if (arr[i][j - 1] == arr[i][j]) temp++;
			else {
				ans = (ans < temp) ? temp : ans;
				temp = 1;
			}
		}
		ans = (ans < temp) ? temp : ans;
	}
	for (int j = 0; j < N; j++) {
		int temp = 1;
		for (int i = 1; i < N; i++) {
			if (arr[i - 1][j] == arr[i][j]) temp++;
			else {
				ans = (ans < temp) ? temp : ans;
				temp = 1;
			}
		}
		ans = (ans < temp) ? temp : ans;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%s", &arr[i]);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < 2; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x < 0 || x >= N || y < 0 || y >= N) continue;
				if (arr[i][j] == arr[x][y]) continue;
				char t = arr[i][j];
				arr[i][j] = arr[x][y];
				arr[x][y] = t;
				check();
				arr[x][y] = arr[i][j];
				arr[i][j] = t;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}