# include <cstdio>

int N, ans;
int T[15], P[15];

void dfs(int n, int sum) {
	if (n == N) {
		if (ans < sum) ans = sum;
		return;
	}

	if (n + T[n] <= N) dfs(n + T[n], sum + P[n]);
	dfs(n + 1, sum);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) scanf("%d %d", &T[i], &P[i]);
	dfs(0, 0);
	printf("%d", ans);
}