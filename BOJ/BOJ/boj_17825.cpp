// https://www.acmicpc.net/problem/17825
# include <cstdio>

int dice[11];
int horse[5];
int ans;
int carr[32][6] = {
{0, 1, 2, 3, 4, 5},
{2, 2, 3, 4, 5, 6},
{4, 3, 4, 5, 6, 7},
{6, 4, 5, 6, 7, 8},
{8, 5, 6, 7, 8, 9},
{10, 21, 22, 23, 24, 30},
{12, 7, 8, 9, 10, 11},
{14, 8, 9, 10, 11, 12},
{16, 9, 10, 11, 12, 13},
{18, 10, 11, 12, 13, 14},
{20, 25, 26, 24, 30, 31},
{22, 12, 13, 14, 15, 16},
{24, 13, 14, 15, 16, 17},
{26, 14, 15, 16, 17, 18},
{28, 15, 16, 17, 18, 19},
{30, 27, 28, 29, 24, 30},
{32, 17, 18, 19, 20, -1},
{34, 18, 19, 20, -1, -1},
{36, 19, 20, -1, -1, -1},
{38, 20, -1, -1, -1, -1},
{40, -1, -1, -1, -1, -1},
{13, 22, 23, 24, 30, 31},
{16, 23, 24, 30, 31, 20},
{19, 24, 30, 31, 20, -1},
{25, 30, 31, 20, -1, -1},
{22, 26, 24, 30, 31, 20},
{24, 24, 30, 31, 20, -1},
{28, 28, 29, 24, 30, 31},
{27, 29, 24, 30, 31, 20},
{26, 24, 30, 31, 20, -1},
{30, 31, 20, -1, -1, -1},
{35, 20, -1, -1, -1, -1}
};

void dfs(int cnt, int score) {
	if (cnt == 10) {
		ans = (score > ans) ? score : ans;
		return;
	}
	for (int i = 1; i <= 4; i++) {
		if (horse[i] == -1) continue;
		bool goflag = true;
		int idx = horse[i];
		int nidx = carr[idx][dice[cnt]];
		for (int j = 1; j <= 4; j++) {
			if (i == j) continue;
			if (horse[j] == -1) continue;
			if (horse[j] == nidx) {
				goflag = false;
				break;
			}
		}
		if (goflag) {
			int tscore = (nidx == -1) ? 0 : carr[nidx][0];
			horse[i] = nidx;
			dfs(cnt + 1, score + tscore);
			horse[i] = idx;
		}
	}
}
	
int main() {
	for (int i = 0; i < 10; i++) scanf("%d", &dice[i]);
	horse[1] = carr[0][dice[0]];
	dfs(1, carr[horse[1]][0]);
	printf("%d\n", ans);
	return 0;
}