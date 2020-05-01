// https://www.acmicpc.net/problem/1062
# include <cstdio>
using namespace std;

char arr[51][16];
bool visited[27];
int N, K;
int ans = 0;

void dfs(int idx, int cnt) {
	if (cnt == K) {
		int res = 0;
		for (int i = 0; i < N; i++) {
			bool flag = true;
			for (int j = 0; j < 16; j++) {
				if (arr[i][j] == '\0') break;
				if (visited[arr[i][j] - 'a']) continue;
				flag = false;
				break;
			}
			if (flag) res++;
		}
		ans = (res > ans) ? res : ans;
		return;
	}

	for (int i = idx + 1; i < 26; i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		dfs(i, cnt + 1);
		visited[i] = 0;
	}
}
int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s", arr[i]);
	}
	if (K < 5) {
		printf("0\n");
		return 0;
	}
	visited[0] = visited[2] = visited['n' - 'a'] = visited['t' - 'a'] = visited['i' - 'a'] = 1;
	K -= 5;
	dfs(-1, 0);
	printf("%d\n", ans);
	return 0;
}