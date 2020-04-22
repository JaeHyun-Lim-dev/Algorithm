// https://www.acmicpc.net/problem/14890
# include <cstdio>

int N, L, arr[100][100], ans;

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) scanf("%d", &arr[i][j]);

	for (int i = 0; i < N; i++) {
		int prev = 1;
		bool flag = true;
		for (int j = 1; j < N; j++) {
			int diff = arr[i][j - 1] - arr[i][j];
			if (diff == 0) prev++;
			else if (diff == 1) { // down
				if (j + L > N) { flag = false; break; }
				for (int k = 1; k < L; k++) {
					if (arr[i][j] == arr[i][j + k]) continue;
					else { flag = false; break; }
				}
				if (flag) { prev = 0; j += (L - 1); }
				else break;
			}
			else if (diff == -1) { // up
				if (prev < L) { flag = false; break; }
				prev = 1;
			}
			else {
				flag = false; break;
			}
		}
		if (flag) { printf("i = %d\n", i); ans++; }
	}
	for (int j = 0; j < N; j++) {
		int prev = 1;
		bool flag = true;
		for (int i = 1; i < N; i++) {
			int diff = arr[i - 1][j] - arr[i][j];
			if (diff == 0) prev++;
			else if (diff == 1) { // down
				if (i + L > N) { flag = false; break; }
				for (int k = 1; k < L; k++) {
					if (arr[i][j] == arr[i + k][j]) continue;
					else { flag = false; break; }
				}
				if (flag) { prev = 0; i += (L - 1); }
				else break;
			}
			else if (diff == -1) { // up
				if (prev < L) { flag = false; break; }
				prev = 1;
			}
			else {
				flag = false; break;
			}
		}
		if (flag) { printf("j = %d\n", j); ans++; }
	}

	printf("%d\n", ans);
	return 0;
}