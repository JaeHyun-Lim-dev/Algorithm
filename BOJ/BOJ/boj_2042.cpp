// https://www.acmicpc.net/problem/2042
# include <cstdio>
using namespace std;

int N, M, K;
long long int arr[1 << 21];
int getidx(int n) {
	int ret = 1;
	while (ret < n) ret *= 2;
	return ret * 2;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	int len = getidx(N);
	for (int i = 0; i < N; i++) scanf("%lld", &arr[len / 2 + i]);
	for (int i = len / 2 - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];

	for (int k = 0; k < M + K; k++) {
		int a, b;
		long long int c;
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) {
			int idx = len / 2 + b - 1;
			long long int gap = arr[idx] - c;
			arr[idx] = c;
			while (idx > 0) {
				arr[idx / 2] -= gap;
				idx /= 2;
			}
		}
		else {
			// b to c	
			int f, r;
			long long int res = 0;
			f = len / 2 + b - 1;
			r = len / 2 + c - 1;
			while (f <= r) {
				if (f % 2 == 0) f /= 2;
				else {
					res += arr[f];
					f++;
					if (f == r) {
						res += arr[f];
						break;
					}
					else f /= 2;
				}
				if (r % 2 == 0) {
					res += arr[r];
					r--;
					r /= 2;
				}
				else r /= 2;
			}
			printf("%lld\n", res);
		}

	}

	return 0;
}