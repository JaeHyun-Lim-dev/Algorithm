# include <cstdio>
# include <queue>
# include <string.h>
using namespace std;

struct ST {
	int x, y;
	int cost;
};

bool operator <(ST s1, ST s2) {
	return s1.cost > s2.cost;
}

char arr[101][101];
int visited[101][101];
int T, N, ans;
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

int main() {
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d", &N);
		memset(visited, 0, sizeof(visited));
		priority_queue<ST> q;
		visited[0][0] = 1;
		q.push({ 0, 0, 1 });

		for (int i = 0; i < N; i++) scanf("%s", &arr[i]);

		while (!q.empty()) {
			ST temp = q.top();
			q.pop();
			if (temp.x == N - 1 && temp.y == N - 1) break;
			for (int k = 0; k < 4; k++) {
				int tx = temp.x + dx[k];
				int ty = temp.y + dy[k];
				if (tx < 0 || tx >= N || ty < 0 || ty >= N || visited[tx][ty]) continue;
				q.push({ tx, ty, temp.cost + (arr[tx][ty] - '0') });
				visited[tx][ty] = temp.cost + (arr[tx][ty] - '0');
			}
		}
		printf("#%d %d\n", t, visited[N - 1][N - 1] - 1);
	}
	return 0;
}