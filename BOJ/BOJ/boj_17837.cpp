// https://www.acmicpc.net/problem/17837 # include <cstdio>
struct ST {
	int x, y;
	int dir;
	int up = -1;
	int down = -1;
};

int N, K;
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int arr[14][14];
ST h[11];

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i <= N + 1; i++) {
		arr[0][i] = 200;
		arr[i][0] = 200;
		arr[N + 1][i] = 200;
		arr[i][N + 1] = 200;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			scanf("%d", &arr[i][j]);
			arr[i][j] *= 100;
		}
	}
	for (int k = 1; k <= K; k++) {
		ST temp;
		scanf("%d %d %d", &temp.x, &temp.y, &temp.dir);
		temp.dir--;
		arr[temp.x][temp.y] += k;
		h[k] = temp;
	}
	for (int ans = 1; ans <= 1000; ans++) {
		for (int k = 1; k <= K; k++) {
			int x, y;
			int d = h[k].dir;
			x = h[k].x + dx[d];
			y = h[k].y + dy[d];
			if (arr[x][y] / 100 == 2) {
				h[k].dir ^= 1;
				d = h[k].dir;
				x = h[k].x + dx[d];
				y = h[k].y + dy[d];
				if (arr[x][y] / 100 == 2) continue;
			}
			if (h[k].down == -1) arr[h[k].x][h[k].y] -= k;
			else {
				h[h[k].down].up = -1;
				h[k].down = -1;
			}
			int cur = k;
			if (arr[x][y] / 100 == 1) {
				int temp;
				while (true) {
					temp = h[cur].down;
					h[cur].down = h[cur].up;
					h[cur].up = temp;
					if (h[cur].down == -1) break;
					cur = h[cur].down;
				}
			}
			int temp = cur;
			while (true) {
				h[temp].x = x;
				h[temp].y = y;
				if (h[temp].up == -1) break;
				temp = h[temp].up;
			}
			if (arr[x][y] % 100 > 0) {
				int top = arr[x][y] % 100;
				while (true) {
					if (h[top].up == -1) break;
					top = h[top].up;
				}
				h[top].up = cur;
				h[cur].down = top;
			}
			else arr[x][y] += cur;
			int size[14][14] = { 0, };
			for (int k = 1; k <= K; k++) {
				size[h[k].x][h[k].y]++;
				if (size[h[k].x][h[k].y] >= 4) {
					printf("%d\n", ans);
					return 0;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}