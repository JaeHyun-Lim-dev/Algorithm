// https://www.acmicpc.net/problem/16954
# include <cstdio>
# include <queue>
using namespace std;

struct ST {
	int x, y, t;
};

char arr[8][9];
int front, rear;
int dx[9] = { 1, -1, 0, 0, 1, 1, -1, -1, 0 };
int dy[9] = { 0, 0, 1, -1, 1, -1, 1, -1, 0 };
bool flag = false;

void time() {
	flag = true;
	for (int i = 7; i > 0; i--) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = arr[i - 1][j];
			if (arr[i][j] == '#') flag = false;
		}
	}
	for (int j = 0; j < 8; j++) {
		arr[0][j] = '.';
	}
}

int main() {
	for (int i = 0; i < 8; i++) {
		scanf("%s", &arr[i]);
	}
	queue<ST> q;
	q.push({ 7, 0, 0 });
	int tx, ty, t;

	while (!q.empty()) {
		ST temp = q.front();
		tx = temp.x;
		ty = temp.y;
		t = temp.t;
		q.pop();
		if (flag || t >= 7) {
			printf("1");
			return 0;
		}
		for (int k = 0; k < 9; k++) {
			int x = tx + dx[k], y = ty + dy[k];
			if (x < 0 || x > 7 || y < 0 || y > 7 || arr[x][y] == '#') continue;
			if (x > 0) {
				if (arr[x - 1][y] == '#') continue;
			}
			q.push({ x, y, t + 1 });
		}
		if (!q.empty() && q.front().t > t) {
			time();
		}
	}

	printf("0");
	return 0;
}