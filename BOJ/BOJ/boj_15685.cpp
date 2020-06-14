// https://www.acmicpc.net/problem/15685

#include <cstdio>
#include <vector>
using namespace std;

int ar[101][101];
int dx[4] = { 0,-1,0,1 }, dy[4] = { 1,0,-1,0 };

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		int x, y, d, g;
		scanf("%d %d %d %d", &y, &x, &d, &g);
		vector<int> dragon;

		ar[x][y] = 1;
		dragon.push_back(d);
		x += dx[d];
		y += dy[d];
		ar[x][y] = 1;

		for (int i = 0; i < g; i++) {
			for (int j = dragon.size() - 1; j >= 0; j--) {
				d = (dragon[j] + 1) % 4;
				x += dx[d];
				y += dy[d];
				ar[x][y] = 1;
				dragon.push_back(d);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			if (ar[i][j] && ar[i + 1][j] && ar[i][j + 1] && ar[i + 1][j + 1]) ans++;

	printf("%d", ans);
}