// https://www.acmicpc.net/problem/3190
# include <cstdio>
# include <vector>
using namespace std;

int N, K, L, front, rear;
int arr[102][102], qx[10000], qy[10000];
typedef pair <int, int> P;
vector <P> v;
int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };// R D L U

int main() {
	scanf("%d %d", &N, &K);
	int x, y;
	char c;
	for (int k = 0; k < K; k++) {
		scanf("%d %d", &x, &y);
		arr[x][y] = 1;
	}
	scanf("%d", &L);
	for (int l = 0; l < L; l++) {
		scanf("%d %c", &x, &c);
		v.push_back(P(x, (c == 'L') ? -1 : 1));
	}
	v.push_back(P(0x7fffffff, 0));

	x = y = 1;
	arr[1][1] = 2;
	qx[rear] = x;
	qy[rear++] = y;
	int d = 0; // R D L U
	int l = 0;
	while (true) {
		if (rear - 1 == v[l].first) {
			d = (d + v[l].second + 4) % 4;
			l++;
		}
		x += dx[d];
		y += dy[d];
		qx[rear] = x;
		qy[rear++] = y;

		if (x < 1 || y < 1 || x > N || y > N || arr[x][y] == 2) {
			printf("%d\n", rear - 1);
			break;
		}
		if (arr[x][y] == 0) {
			arr[qx[front]][qy[front]] = 0;
			front++;
		}
		arr[x][y] = 2;
	}

	return 0;
}