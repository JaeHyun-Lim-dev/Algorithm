#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 987654321;

int abs(int x) {
	return (x > 0) ? x : -x;
}

struct ST {
	int x, y, val;
};

vector<ST> S, H; // S 계단, H 사람
vector<int> a[2]; // 계단 번호
int T, N, ans, arr[10][10];

void dfs(int n) {
	if (n == H.size()) {
		int res = 0;
		for (int k = 0; k < 2; k++) {
			if (a[k].size() == 0) continue;
			int dist[20], dp[20] = { 0, };
			//거리계산
			for (int i = 0; i < a[k].size(); i++) dist[i] = abs(S[k].x - H[a[k][i]].x) + abs(S[k].y - H[a[k][i]].y);
			
			sort(dist, dist + a[k].size()); //정렬

			//초기값 설정, 3명까지는 조건 없음
			for (int i = 0; (i < 3) || i < a[k].size(); i++) dp[i] = dist[i] + S[k].val + 1;

			//dp[i] = max((i-3)의 끝시간, i의 도착시간) + 계단길이
			for (int i = 3; i < a[k].size(); i++) dp[i] = max(dp[i - 3] - 1, dist[i]) + S[k].val + 1;

			if (res < dp[a[k].size() - 1]) res = dp[a[k].size() - 1];
		}

		if (ans > res) ans = res;
		return;
	}

	//0번 계단
	a[0].push_back(n);
	dfs(n + 1);
	a[0].pop_back();

	//1번 계단
	a[1].push_back(n);
	dfs(n + 1);
	a[1].pop_back();
}

int main() {
	scanf("%d", &T);
	for (int t_c = 1; t_c <= T; t_c++) {
		ans = INF; S.clear(); H.clear(); a[0].clear(); a[1].clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] > 1)
					S.push_back({ i,j,arr[i][j] });
				else if (arr[i][j])
					H.push_back({ i,j });
			}
		}

		dfs(0);
		printf("#%d %d\n", t_c, ans);
	}
}