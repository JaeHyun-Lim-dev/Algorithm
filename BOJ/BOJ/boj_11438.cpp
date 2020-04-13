// https://www.acmicpc.net/problem/11438
# include <cstdio>
# include <vector>
# include <cmath>
# define MAX_NODE 100001
using namespace std;

int N, M, ans;
vector<int> arr[MAX_NODE];
int parent[18][MAX_NODE];
int depth[MAX_NODE];

void Tree(int idx, int p) {
	depth[idx] = depth[p] + 1;
	parent[0][idx] = p;

	int mlevel = (int)floor(log2(MAX_NODE)); // maximum level
	for (int i = 1; i <= mlevel; i++) {
		int temp = parent[i - 1][idx];
		parent[i][idx] = parent[i - 1][temp];
	}

	int s = arr[idx].size();
	for (int i = 0; i < s; i++) {
		int nidx = arr[idx][i];
		if (nidx != p) Tree(nidx, idx);
	}
}

int lca(int x, int y) {
	int d = depth[y] - depth[x];

	for (int i = 17; i >= 0; i--) { // depth 맞추기
		if (d >= (1 << i)) {
			d -= (1 << i);
			y = parent[i][y];
		}
	}
	if (x == y) return x;
	for (int i = 17; i >= 0; i--) {
		if (parent[i][x] != parent[i][y]) { // 조상 찾을때까지 타고 올라감
			x = parent[i][x];
			y = parent[i][y];
		}
	}
	return parent[0][x];
}

int main() {
	scanf("%d", &N);
	int x, y;
	for (int i = 1; i < N; i++) {
		scanf("%d %d", &x, &y);
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	scanf("%d", &M);
	depth[0] = -1;
	Tree(1, 0);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x, &y);
		int ans = (depth[x] > depth[y]) ? lca(y, x) : lca(x, y); // 최소공통조상 찾고 리턴
		printf("%d\n", ans);
	}

	return 0;
}