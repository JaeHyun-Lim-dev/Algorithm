// https://www.acmicpc.net/problem/11723
# include <cstdio>
# include <string>
# include <iostream>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int s[21] = { 0, }, M;
	cin >> M;
	for (; M > 0; M--) {
		string buffer;
		int x;
		cin >> buffer;

		if (buffer == "all") {
			for (int i = 1; i <= 20; i++) s[i] = 1;
			continue;
		}
		else if (buffer == "empty") {
			for (int i = 1; i <= 20; i++) s[i] = 0;
			continue;
		}
		else { 
			cin >> x;
			if (buffer == "add") s[x] = 1;
			else if (buffer == "remove") s[x] = 0;
			else if (buffer == "check") cout << s[x] << "\n";
			else if (buffer == "toggle") s[x] ^= 1;
		}

	}

	return 0;
}