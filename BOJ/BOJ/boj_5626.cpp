// https://www.acmicpc.net/problem/5626
# include <cstdio>
# include <vector>
using namespace std;

int arr[10000];
int dp[10000][5001];
int N;
int H;
int main() {
	scanf("%d", &N);
	H = N / 2;
	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);
	dp[0][0] = (arr[0] <= 0) ? 1 : 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= H; j++) {
			if (dp[i][j] == 0) continue;
			if (arr[i + 1] == -1) {
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
				if (j > 0) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000007;
				if (j <= H - 1) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % 1000000007;
			}
			else {
				if (j == arr[i + 1]) dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % 1000000007;
				else if (j - 1 == arr[i + 1]) dp[i + 1][j - 1] = (dp[i + 1][j - 1] + dp[i][j]) % 1000000007;
				else if (j + 1 == arr[i + 1]) dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % 1000000007;
			}
		}
	}
	printf("%d\n", dp[N - 1][0]);
	return 0;
}