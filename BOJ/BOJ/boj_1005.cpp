// https://www.acmicpc.net/problem/1005
# include <cstdio>
# include <vector>
# include <queue>
using namespace std;

int T, N, K, D, X, Y, W;
int time[1001];

int main() {
	scanf("%d", &T);

	while (T--) {
		vector<int> order[1001];
		queue<int> q;
		long long dp[1001] = { 0, };
		int size[1001] = { 0, };
		scanf("%d %d", &N, &K);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &time[i]);
		}

		int start = 0;
		while (K--) {
			scanf("%d %d", &X, &Y);
			size[Y]++;
			order[X].push_back(Y);
		}
		scanf("%d", &W);

		for (int i = 1; i <= N; i++) {
			if (size[i] == 0) q.push(i);
			dp[i] = time[i];
		}
		int temp;
		while (!q.empty()) {
			temp = q.front();
			q.pop();
			if (temp == W) break;
			int vsize = order[temp].size();
			for (int i = 0; i < vsize; i++) {
				int next = order[temp][i];
				size[next]--;
				dp[next] = (dp[next] > dp[temp] + time[next]) ? dp[next] : dp[temp] + time[next];
				if (size[next] == 0) q.push(next);
			}
		}
		printf("%lld\n", dp[W]);
	}

	return 0;
}