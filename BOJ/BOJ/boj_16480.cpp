// https://www.acmicpc.net/problem/16480
# include <cstdio>

int main() {
	int R, r;
	long long ans;
	scanf("%d %d", &R, &r);
	ans = R - (2 * r);
	ans *= R;
	printf("%lld", ans);

	return 0;
}