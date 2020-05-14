# include <cstdio>
# include <queue>
using namespace std;

struct atom {
	int x, y, dir, energy;
	int alive = 1;
};

struct ST {
	int index1, index2;
	int time;
};

bool operator<(ST s1, ST s2) {
	if (s1.time != s2.time) return s1.time > s2.time;
	else return s1.index1 > s2.index1;
}

int T, N, ans;
atom arr[1001];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { 1, -1, 0, 0 };
priority_queue<ST> pq;

int main() {
	scanf("%d", &T);

	for (int t_c = 1; t_c <= T; t_c++) {
		scanf("%d", &N);
		atom temp;
		temp.alive = 1;
		ans = 0;
		while (!pq.empty()) pq.pop();

		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &temp.x, &temp.y, &temp.dir, &temp.energy);
			temp.x *= 2;
			temp.y *= 2;
			arr[i] = temp;
		}

		for (int i = 0; i < N - 1; i++) {
			for (int j = i; j < N; j++) {
				atom a1 = arr[i];
				atom a2 = arr[j];
				ST temp;
				if (a1.x == a2.x) {
					if (a1.y < a2.y) { // a1�� ��������� ��, a2�� ��
						if (a1.dir != 0 || a2.dir != 1) continue;
						temp.index1 = i;
						temp.index2 = j;
						temp.time = (a2.y - a1.y) / 2;
						pq.push(temp);
						continue;
					}
					else {
						if (a2.dir != 0 || a1.dir != 1) continue;
						temp.index1 = i;
						temp.index2 = j;
						temp.time = (a1.y - a2.y) / 2;
						pq.push(temp);
						continue;
					}
				}
				else if (a1.y == a2.y) {
					if (a1.x < a2.x) { // a1�� ��, a2�� ��
						if (a1.dir != 3 || a2.dir != 2) continue;
						temp.index1 = i;
						temp.index2 = j;
						temp.time = (a2.x - a1.x) / 2;
						pq.push(temp);
						continue;
					}
					else {
						if (a2.dir != 3 || a1.dir != 2) continue;
						temp.index1 = i;
						temp.index2 = j;
						temp.time = (a1.x - a2.x) / 2;
						pq.push(temp);
						continue;
					}
				}

				else {
					if (a1.x > a2.x) { // �׻� a1.x�� �� ���� (a1.x < a2.x)�̵��� ����
						atom ta = a1;
						a1 = a2;
						a2 = ta;
					}
					int dx = a2.x - a1.x;
					int dy;
					if (a1.y < a2.y) { // a1�� ���ϴ�, a2�� ����
						dy = a2.y - a1.y;
						if (dx != dy) continue;
						if (a1.dir == 3) { // a1�� ���������� �̵��ϸ� a2�� �Ʒ��� �̵�
							if (a2.dir != 1) continue;
							temp.index1 = i;
							temp.index2 = j;
							temp.time = dx;
							pq.push(temp);
							continue;
						}
						else if (a1.dir == 0) { // a1�� ���� �̵��ϸ� a2�� �������� �̵�
							if (a2.dir != 2) continue;
							temp.index1 = i;
							temp.index2 = j;
							temp.time = dx;
							pq.push(temp);
							continue;
						}
					}
					else if (a1.y > a2.y) { // a1�� �»��, a2�� ���ϴ�
						dy = a1.y - a2.y;
						if (dx != dy) continue;
						if (a1.dir == 3) { // a1�� ���������� �̵��ϸ� a2�� ���� �̵�
							if (a2.dir != 0) continue;
							temp.index1 = i;
							temp.index2 = j;
							temp.time = dx;
							pq.push(temp);
							continue;
						}
						else if (a1.dir == 1) { // a1�� �Ʒ��� �̵��ϸ� a2�� �������� �̵�
							if (a2.dir != 2) continue;
							temp.index1 = i;
							temp.index2 = j;
							temp.time = dx;
							pq.push(temp);
							continue;
						}
					}
				}
			}
		}

		while (!pq.empty()) {
			ST now = pq.top();
			int time = now.time;
			while (!pq.empty() && pq.top().time == time) {
				now = pq.top();
				pq.pop();
				atom a1 = arr[now.index1];
				atom a2 = arr[now.index2];

				if (a1.alive == 0 || a2.alive == 0) continue; // �̹� �浹�ؼ� �浹�� �Ͼ�� ����
				else {
					a1.alive = -1;
					arr[now.index1] = a1;
					a2.alive = -1;
					arr[now.index2] = a2;
				}
			}

			for (int i = 0; i < N; i++) {
				if (arr[i].alive > -1) continue;
				else {
					arr[i].alive = 0;
					ans += arr[i].energy;
				}
			}
		}
		printf("#%d %d\n", t_c, ans);
	}
	return 0;
}