// https://www.acmicpc.net/problem/2042
#include <cstdio>
using namespace std;

int N, M, K, len;
long long int arr[1 << 21];

int getLen(int n) {
	int res = 1;
	while (res < n) res *= 2;
	return res * 2;
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	int len = getLen(N);

	for (int i = 0; i < N; i++) scanf("%lld", &arr[len / 2 + i]);
	for (int i = (len / 2) - 1; i > 0; i--) arr[i] = arr[i * 2] + arr[i * 2 + 1];
	int a;
	for (int i = 0; i < M + K; i++) {
		scanf("%d", &a);
		if (a == 1) {
			int b;
			long long int c;
			scanf("%d %lld", &b, &c);
			b = len / 2 + b - 1;
			arr[b] = c;
			b /= 2;
			while (b > 0) {
				arr[b] = arr[b * 2] + arr[b * 2 + 1];
				b /= 2;
			}
		}
		else {
			int b, c;
			scanf("%d %d", &b, &c);
			int f, r;
			long long int sum = 0;
			f = len / 2 + b - 1;
			r = len / 2 + c - 1;
			while (f <= r) {
				// f
				if (f % 2 == 0) f /= 2;
				else {
					sum += arr[f];
					f++;
					f /= 2;
				}
				//r
				if (r % 2 != 0) r /= 2;
				else {
					sum += arr[r];
					r--;
					r /= 2;
				}
			}
			printf("%lld\n", sum);
		}
	}

	return 0;
}