// https://www.acmicpc.net/problem/1922
# include <cstdio>
# include <queue>
using namespace std;

struct ST {
	int x, y;
	int cost;
};
bool operator<(ST s1, ST s2) {
	return s1.cost > s2.cost;
}
int N, M, ans;
int root[1001];
priority_queue<ST> q;

int find(int x) {
	if (root[x] == x) return x;
	return (root[x] = find(root[x]));
}
void uni(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y) return;
	root[y] = x;
}

int main() {
	int a, b, c;
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) root[i] = i;

	while (M--) {
		scanf("%d %d %d", &a, &b, &c);
		q.push({ a, b, c });
	}
	int cnt = 0;
	while (cnt < N - 1) {
		ST temp = q.top();
		q.pop();

		if (find(temp.x) == find(temp.y)) continue;
		cnt++;
		ans += temp.cost;
		uni(temp.x, temp.y);
	}
	printf("%d\n", ans);

	return 0;
}