// https://www.acmicpc.net/problem/4179
# include <cstdio>
# include <queue>
using namespace std;

struct ST {
	int x;
	int y;
	int cnt;
};

char arr[1001][1001];
short visited[1001][1001] = { 0, };
int R, C;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++) scanf("%s", &arr[i]);

	queue<ST> q;
	queue<ST> f;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (arr[i][j] == 'F') {
				f.push({ i, j, 0 });
				visited[i][j] = 1;
			}
			else if (arr[i][j] == 'J') {
				q.push({ i, j, 0 });
				visited[i][j] = 1;
			}
		}
	}

	int x, y;
	ST temp;
	ST tempf;
	bool flag = true;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		while (!f.empty() && f.front().cnt <= temp.cnt) {
			tempf = f.front();
			f.pop();
			for (int k = 0; k < 4; k++) {
				x = tempf.x + dx[k];
				y = tempf.y + dy[k];
				if (x < 0 || y < 0 || x >= R || y >= C || visited[x][y] == 1) continue;
				if (arr[x][y] == '#') continue;
				visited[x][y] = 1;
				f.push({ x, y, tempf.cnt + 1 });
			}
		}

		for (int k = 0; k < 4; k++) {
			x = temp.x + dx[k];
			y = temp.y + dy[k];
			if (x < 0 || y < 0 || x >= R || y >= C) {
				printf("%d\n", temp.cnt + 1);
				return 0;
			}
			else if (visited[x][y] == 1 || arr[x][y] == '#') continue;
			visited[x][y] = 1;
			q.push({ x, y, temp.cnt + 1 });
		}
	}

	printf("IMPOSSIBLE\n");
	return 0;
}