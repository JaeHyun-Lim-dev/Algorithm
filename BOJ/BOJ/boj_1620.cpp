// https://www.acmicpc.net/problem/1620
# include <cstdio>
# include <cstring>
# include <string>
# include <algorithm>
using namespace std;

struct ST {
	int num;
	char name[21];
};

int N, M;
ST poke1[100000], poke2[100000];
char buffer[21];

bool compare(ST s1, ST s2) {
	return (strcmp(s1.name, s2.name) < 0);
}
int pow(int n, int k) {
	int ans = 1;
	for (int i = 0; i < k; i++) ans *= n;
	return ans;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		ST p;
		p.num = i + 1;
		scanf("%s", &p.name);
		poke1[i] = poke2[i] = p;
	}
	sort(poke1, poke1 + N, compare);

	while (M--) {
		scanf("%s", &buffer);
		if (buffer[0] - '0' > 0 && buffer[0] - '0' < 10) {
			int pnum = 0;
			for (int k = 0; k < strlen(buffer); k++) {
				pnum += (buffer[k] - '0') * pow(10, strlen(buffer) - k - 1);
			}
			printf("%s\n", poke2[pnum - 1].name);
		}
		else {
			int front = 0;
			int rear = N - 1;
			int mid = rear / 2;
			while (true) {
				if (strcmp(poke1[mid].name, buffer) == 0) {
					printf("%d\n", poke1[mid].num);
					break;
				}
				if (strcmp(poke1[mid].name, buffer) < 0) {
					front = mid + 1;
					mid = (rear + front) / 2;
				}
				else {
					rear = mid - 1;
					mid = (rear + front) / 2;
				}
			}
		}
	}

	return 0;
}