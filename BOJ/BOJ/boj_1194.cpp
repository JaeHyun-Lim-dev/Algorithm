// https://www.acmicpc.net/problem/1194
#include <cstdio>

struct ST {
	int x, y, cnt, key;
};

char arr[50][50];
int visited[50][50][1 << 6];
int N, M, front, rear;
int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
ST q[50 * 50 * (1 << 6)];

void push(int x, int y, int c, int k) {
	if (x < 0 || y < 0 || x >= N || y >= M || arr[x][y] == '#') return;
	if (arr[x][y] >= 'A' && arr[x][y] <= 'F' && !(k & (1 << (arr[x][y] - 'A')))) return;

	if (arr[x][y] >= 'a' && arr[x][y] <= 'f') k = k | (1 << (arr[x][y] - 'a'));
	if (visited[x][y][k] == 1) return;

	q[rear++] = { x, y, c, k };
	visited[x][y][k] = 1;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == '0') push(i, j, 0, 0);
		}
	}

	while (front < rear) {
		ST temp = q[front++];
		if (arr[temp.x][temp.y] == '1') {
			printf("%d", temp.cnt);
			return 0;
		}
		for (int k = 0; k < 4; k++) {
			push(temp.x + dx[k], temp.y + dy[k], temp.cnt + 1, temp.key); // check, queue push
		}
	}

	printf("-1");
	return 0;
}