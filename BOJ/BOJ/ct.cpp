#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

string solution(string compressed) { // )�� ���� ������ ��ȣ ������ ���ڿ� ����
	int csize = compressed.length();
	stack<string> st;
	for (int i = 0; i < csize; i++) {
		if (compressed[i] == '(') st.push("(");
		else if (compressed[i] == ')') {
			string total = "";
			string temp = st.top(); st.pop();
			while (st.top() != "(") { // "("���� pop�ϸ鼭 ���ڿ� �ջ�
				temp = st.top(); st.pop();
			}
			st.pop(); // "(" ����
			int r = stoi(st.top()); st.pop();
			while (r--) total += temp; // total = ���ÿ� �ٽ� �ø� ���ڿ�
			st.push(total);
		}
		else if (compressed[i] >= '0' && compressed[i] <= '9') {
			string nums = "";
			while (compressed[i] >= '0' && compressed[i] <= '9') {
				nums += compressed[i]; i++;
			}
			i--; st.push(nums);
		}
		else if (compressed[i] >= 'a' && compressed[i] <= 'z') {
			string ts = "";
			while (compressed[i] >= 'a' && compressed[i] <= 'z') {
				ts += compressed[i]; i++;
			}
			i--; st.push(ts);
		}
	}
	string answer = "";
	while (!st.empty()) {
		answer = st.top() + answer;
		st.pop();
	}
	return answer;
}


int solution2(vector<vector<int>> board) {
	int answer = 0;
	int dx[] = { 1, -1, 0, 0, 1, 1, -1, -1 };
	int dy[] = { 0, 0, 1, -1, -1, 1, -1, 1 };
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j]) continue;
			int cnt = 0;
			for (int k = 0; k < 8; k++) {
				int x = i + dx[k], y = j + dy[k];
				if (x < 0 || x >= 8 || y < 0 || y >= 8) continue;
				if (board[x][y] < 2) continue;
				int temp = 0;
				bool flag = false;
				while (true) {
					if (x < 0 || x >= 8 || y < 0 || y >= 8) break;
					if (board[x][y] == 1) {
						flag = true; break; 
					}
					if (board[x][y] == 2) {
						x += dx[k]; y += dy[k]; temp++;
					}
					else break;
				}
				if (flag && temp > 0) cnt += temp;
			}
			if (cnt > answer) answer = cnt;
		}
	}
	return answer;
}