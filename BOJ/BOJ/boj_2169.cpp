// https://www.acmicpc.net/problem/2169
# include <cstdio>
# define MIN_COST -1000001;

int N, M;
int dp[1001][1001][3];// ¾Æ·¡/¿ì/ÁÂ
int arr[1001][1001];
int ans;

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			scanf("%d", &arr[i][j]);
			for (int k = 0; k < 3; k++) {
				dp[i][j][k] = MIN_COST;
			}
		}
	}
	for (int j = 1; j <= M; j++) {
		dp[1][j][0] = dp[1][j - 1][1] + arr[1][j];
		dp[1][j][1] = dp[1][j - 1][1] + arr[1][j];
		dp[1][j][2] = dp[1][j - 1][1] + arr[1][j];
	}

	for (int i = 2; i <= N; i++) {
		for (int j = 1; j <= M; j++) { // 0
			int temp = dp[i - 1][j][0];
			temp = (temp > dp[i - 1][j][1]) ? temp : dp[i - 1][j][1];
			temp = (temp > dp[i - 1][j][2]) ? temp : dp[i - 1][j][2];
			dp[i][j][0] = temp + arr[i][j];
		}
		for (int j = 2; j <= M; j++) { // 1
			int temp = dp[i][j - 1][0];
			temp = (temp > dp[i][j - 1][1]) ? temp : dp[i][j - 1][1];
			dp[i][j][1] = temp + arr[i][j];
		}
		for (int j = M - 1; j >= 0; j--) { // 2
			int temp = dp[i][j + 1][0];
			temp = (temp > dp[i][j + 1][2]) ? temp : dp[i][j + 1][2];
			dp[i][j][2] = temp + arr[i][j];
		}
	}
	ans = dp[N][M][0];
	ans = (ans > dp[N][M][1]) ? ans : dp[N][M][1];

	printf("%d\n", ans);

	return 0;
}