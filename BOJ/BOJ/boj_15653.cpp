// https://www.acmicpc.net/problem/15653
# include <cstdio>
# include <vector>
# include <queue>
using namespace std;

struct ST {
	pair<int, int> R, B;
	int prev;
	int cnt;
};

char arr[10][11];
int visited[10][10][10][10];
int N, M, dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };
queue<ST> q;

bool qadd(pair<int, int> p1, pair<int, int> p2, int dir, int cnt) {
	pair<int, int> r = p1, b = p2;
	short rflag = 1, bflag = 1;
	bool flag = false;
	while (rflag || bflag) {
		r.first += rflag * dx[dir];
		r.second += rflag * dy[dir];
		b.first += bflag * dx[dir];
		b.second += bflag * dy[dir];
		if (rflag && arr[r.first][r.second] == 'O') {
			rflag = 0; r.first = r.second = 0;
			flag = true;
		}
		if (bflag && arr[b.first][b.second] == 'O') {
			bflag = 0; flag = false;
			return false;
		}
		if (rflag && arr[r.first][r.second] == '#') {
			rflag = 0;
			r.first -= dx[dir];
			r.second -= dy[dir];
		}
		if (bflag && arr[b.first][b.second] == '#') {
			bflag = 0;
			b.first -= dx[dir];
			b.second -= dy[dir];
		}
		if (r.first == b.first && r.second == b.second) {
			r.first -= rflag * dx[dir];
			r.second -= rflag * dy[dir];
			b.first -= bflag * dx[dir];
			b.second -= bflag * dy[dir];
			rflag = bflag = 0;
		}
	}

	if (visited[r.first][r.second][b.first][b.second]) return false;
	visited[r.first][r.second][b.first][b.second] = 1;
	q.push({ r, b, dir, cnt });

	return flag;
}



int main() {
	ST temp;
	pair<int, int> P;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%s", &arr[i]);
		for (int j = 0; j < M; j++) {
			if (arr[i][j] == 'R') {
				P.first = i;
				P.second = j;
				temp.R = P;
			}
			else if (arr[i][j] == 'B') {
				P.first = i;
				P.second = j;
				temp.B = P;
			}
		}
	}
	temp.prev = 6;
	temp.cnt = 0;
	visited[temp.R.first][temp.R.second][temp.B.first][temp.B.second] = 1;
	q.push(temp);

	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int k = 0; k < 4; k++) {
			if (k == temp.prev) continue;
			if (k + temp.prev == 1 || k + temp.prev == 5) continue;
			if (qadd(temp.R, temp.B, k, temp.cnt + 1)) {
				printf("%d\n", temp.cnt + 1);
				return 0;
			}
		}
	}
	printf("-1\n");
	return 0;
}