// https://programmers.co.kr/learn/courses/30/lessons/64064
#include <string>
#include <vector>
using namespace std;

int visited[9] = { 0, };
int bit[1<<8] = { 0, };

void dfs(int checker, int cnt, vector<string> uid, vector<string> bid, int* ans) {
    if (cnt == bid.size()) {
        if (bit[checker]) return;
        bit[checker] = 1;
        *ans += 1;
        return;
    }
    for (int i = 0; i < uid.size(); i++) {
        if (visited[i] || uid[i].size() != bid[cnt].size()) continue;
        bool flag = true;
        for (int j = 0; flag && j < uid[i].size(); j++) {
            if (bid[cnt][j] == '*' || bid[cnt][j] == uid[i][j]) continue;
            flag = false;
        }
        if (flag) {
            visited[i] = 1;
            dfs(checker + (1<<i), cnt + 1, uid, bid, ans);
            visited[i] = 0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    dfs(0, 0, user_id, banned_id, &answer);
    
    return answer;
}
