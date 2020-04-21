// https://www.acmicpc.net/problem/13458
# include <cstdio>

int N, i, A[1000001], B, C;
long long ans;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	scanf("%d %d", &B, &C);
	for (int i = 0; i < N; i++) {
		if (A[i] <= B) continue;
		A[i] -= B;
		ans += A[i] / C;
		if (A[i] % C)ans++;
	}
	ans += N;
	printf("%lld", ans);
	return 0;
}