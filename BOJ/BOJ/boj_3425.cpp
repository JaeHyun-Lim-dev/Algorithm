// https://www.acmicpc.net/problem/3425
#include <cstdio>
# include <vector>
using namespace std;

long long st[1001];
char buffer[100001][5];
long long num[100001];
long long temp, res, a, b;
int N, numrear, rear, cnt, numcnt;
const long long check1 = 1000000000;
const long long check2 = -1000000000;
bool flag = false;

void gs(int idx) {
	if (buffer[idx][0] == 'A') { // add
		a = st[--rear];
		b = st[--rear];
		res = a + b;
		if (res > check1 || res < check2) {
			flag = true;
			return;
		}
		st[rear++] = a + b;
	}
	else if (buffer[idx][0] == 'D') { // dup, div
		if (buffer[idx][1] == 'U') { // dup
			st[rear] = st[rear - 1];
			rear++;
		}
		else { // div
			a = st[--rear]; // 제수
			b = st[--rear]; // 피제수
			if (a == 0) {
				flag = true;
				return;
			}
			st[rear++] = b / a;
		}
	}
	else if (buffer[idx][0] == 'S') { // swp, sub
		if (buffer[idx][1] == 'W') {
			long long temp;
			temp = st[rear - 1];
			st[rear - 1] = st[rear - 2];
			st[rear - 2] = temp;
		}
		else {
			a = st[--rear];
			b = st[--rear];
			res = b - a;
			if (res > check1 || res < check2) {
				flag = true;
				return;
			}
			st[rear++] = b - a;
		}
	}
	else if (buffer[idx][0] == 'M') { // mul, mod
		if (buffer[idx][1] == 'U') { // mul
			a = st[--rear];
			b = st[--rear];
			res = a * b;
			if (res > check1 || res < check2) {
				flag = true;
				return;
			}
			st[rear++] = a * b;
		}
		else {
			a = st[--rear]; // 제수
			b = st[--rear]; // 피제수		
			if (a == 0) {
				flag = true;
				return;
			}
			a = (a < 0) ? -a : a;
			if (b < 0) {
				b *= -1;
				st[rear++] = (b % a) * (-1);
			}
			else st[rear++] = (b % a);
		}
	}
	else if (buffer[idx][0] == 'I') { // inv
		st[rear - 1] *= -1;
	}
	else if (buffer[idx][0] == 'N') { // num
		temp = num[numrear++];
		st[rear++] = temp;
	}
	else { // pop
		if (rear == 0) {
			flag = true;
			return;
		}
		rear--;
	}
	return;
}

int main()
{
	while (true) {
		numcnt = rear = cnt = numrear = 0;
		while (true) {
			scanf("%s", buffer[cnt++]);
			if (buffer[cnt - 1][0] == 'N') {
				scanf("%lld", &temp);
				num[numcnt++] = temp;
			}
			if (buffer[cnt - 1][0] == 'E') break;
			else if (buffer[cnt - 1][0] == 'Q') return 0;
		}
		cnt--;
		scanf("%d", &N);
		while (N--) {
			numrear = 0;
			rear = 0;
			flag = false;
			scanf("%lld", &temp);
			st[rear++] = temp;
			for (int i = 0; i < cnt; i++) {
				gs(i);
				if (flag) break;
			}
			if (flag || rear != 1) printf("ERROR\n");
			else printf("%lld\n", st[rear - 1]);
		}
		printf("\n");
	}
	return 0;
}