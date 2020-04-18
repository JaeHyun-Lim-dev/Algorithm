// https://www.acmicpc.net/problem/14395
# include <cstdio>
# include <queue>
# include <vector>
using namespace std;

struct ST {
	long long int num;
	long long int cnt;
	vector <char> v;
};
long long int s, t;
queue<ST> q;

int main() {
	scanf("%lld %lld", &s, &t);
	if (s == t) {
		printf("0\n");
		return 0;
	}

	q.push({ s, 0 });

	while (!q.empty()) {
		int qs = q.size();
		for (int i = 0; i < qs; i++) {
			ST temp = q.front();
			q.pop();
			if (temp.num == t) {
				int vs = temp.v.size();
				for (int k = 0; k < vs; k++) printf("%c", temp.v[k]);
				return 0;
			}
			// *
			ST next;
			next.num = temp.num * temp.num;
			if (next.num <= t && next.num != temp.num) {
				next.cnt = temp.cnt + 1;
				next.v = temp.v;
				next.v.push_back('*');
				q.push(next);
			}
			// +
			next.num = temp.num + temp.num;
			if (next.num <= t && next.num != temp.num) {
				next.cnt = temp.cnt + 1;
				next.v = temp.v;
				next.v.push_back('+');
				q.push(next);
			}
			// /
			if (temp.cnt == 0 && next.num != temp.num) {
				next.num = temp.num / temp.num;
				next.cnt = temp.cnt + 1;
				next.v = temp.v;
				next.v.push_back('/');
				q.push(next);
			}
		}
	}
	printf("-1\n");
	return 0;
}
