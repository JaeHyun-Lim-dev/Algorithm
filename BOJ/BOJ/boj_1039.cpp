// https://www.acmicpc.net/problem/1039
#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

int ans = -1, nsize, K;
string num;
int cnt = 0;
queue<string> q;
map<string, int> m;

int main() {
	cin >> num;
	cin >> K;
	nsize = num.length();
	q.push(num);
	m[num] = 0;
	while (!q.empty()) {
		int t = q.size();
		cnt++;
		while (t--) {
			string temp = q.front();
			q.pop();
			for (int i = 0; i < nsize; i++) {
				for (int j = i + 1; j < nsize; j++) {
					swap(temp[i], temp[j]);
					if (temp[0] == '0') {
						swap(temp[i], temp[j]);
						continue;
					}
					auto it = m.find(temp);
					if (it == m.end()) {
						m[temp] = cnt;
						if (cnt % 2 == K % 2 && ans < stoi(temp)) ans = stoi(temp);
						q.push(temp);
					}
					else {
						if (m[temp] % 2 == K % 2) {
							if (cnt % 2 != K % 2) {
								m[temp] = cnt;
								q.push(temp);
							}
							else if (m[temp] == 0 && ans < stoi(temp)) ans = stoi(temp);
						}
						if (m[temp] % 2 != K % 2) {
							if (cnt % 2 == K % 2) {
								if (ans < stoi(temp)) {
									ans = stoi(temp);
									q.push(temp);
								}
							}
						}
					}
					swap(temp[i], temp[j]);
				}
			}
		}
		if (cnt == K) break;
	}
	cout << ans;
	return 0;
}