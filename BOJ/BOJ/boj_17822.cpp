// https://www.acmicpc.net/problem/17822
# include <cstdio>
# include <algorithm>
using namespace std;

int arr[51][51];
int checker[51][51];
int N, M, T, x, d, k, ans;

int main() {
	scanf("%d %d %d", &N, &M, &T);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	while (T--) {
		bool dflag = false;
		int cnt = 0, total = 0;
		scanf("%d %d %d", &x, &d, &k);
		if (!d) k = M - k;
		for (int i = 1; i <= N; i++) {
			if (i % x > 0) continue;
			rotate(arr[i] + 1, arr[i] + 1 + k, arr[i] + M + 1);
		}
		for (int i = 1; i < N; i++) {
			for (int j = 1; j <= M; j++) {
				if (!arr[i][j]) continue;
				if (arr[i][j] == arr[i + 1][j]) {
					checker[i][j] = -1;
					checker[i + 1][j] = -1;
					dflag = true;
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j < M; j++) {
				if (!arr[i][j]) continue;
				if (arr[i][j] == arr[i][j + 1]) { // °¡·Î
					checker[i][j] = -1;
					checker[i][j + 1] = -1;
					dflag = true;
				}
			}
			if (arr[i][M] > 0 && arr[i][M] == arr[i][1]) {
				checker[i][M] = -1;
				checker[i][1] = -1;
				dflag = true;
			}
		}

		if (dflag) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (checker[i][j] == -1) {
						checker[i][j] = 0;
						arr[i][j] = 0;
					}
				}
			}
		}
		else {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (arr[i][j]) {
						cnt++;
						total += arr[i][j];
					}
				}
			}
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= M; j++) {
					if (!arr[i][j]) continue;
					if (arr[i][j] * cnt < total) {
						arr[i][j]++;
					}
					else if (arr[i][j] * cnt > total) {
						arr[i][j]--;
					}

				}
			}
		}
		if (!dflag && !cnt) break;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			ans += arr[i][j];
		}
	}
	printf("%d\n", ans);

	return 0;
}