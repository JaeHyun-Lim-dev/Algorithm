// https://www.acmicpc.net/problem/16234
# include <cstdio>
using namespace std;

int N, L, R;
int arr[51][51];
int visited[51][51];
int qx[50 * 50];
int qy[50 * 50];
int front, rear;
int dx[] = { 1, -1, 0, 0 }, dy[] = { 0, 0, 1, -1 };

int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	int res = 1;
	bool flag = true;
	for (res = 1; res <= 2000; res++) {
		flag = false;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (visited[i][j] == res) continue;
				int num = 1;
				int tsum = arr[i][j];
				front = rear = 0;
				visited[i][j] = res;
				qx[rear] = i;
				qy[rear++] = j;
				while (front < rear) {
					int tx = qx[front];
					int ty = qy[front++];
					for (int k = 0; k < 4; k++) {
						int x = tx + dx[k], y = ty + dy[k];
						if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y] == res) continue;
						int d = arr[x][y] - arr[tx][ty];
						d = (d < 0) ? -d : d;
						if (d <= R && d >= L) {
							qx[rear] = x;
							qy[rear++] = y;
							visited[x][y] = res;
							tsum += arr[x][y];
							num++;
						}
					}
				}
				if (num > 1) {
					flag = true;
					int val = tsum / num;
					for (int r = 0; r < rear; r++) {
						arr[qx[r]][qy[r]] = val;
					}
				}
			}
		}
		if (!flag) {
			printf("%d\n", res - 1);
			return 0;
		}
	}
	return 0;
}