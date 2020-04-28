#include <string>
#include <vector>
using namespace std;

int map[102][102][2] = { 0 , };

bool check(int x, int y, int a, int b) {
    bool flag = false;
    if (!b && map[x][y][a] == 0) return true;
    if (a == 0) { // 기둥
        if (y == 0 || map[x][y - 1][0] || map[x][y][1]) return true;
        if (x > 0 && map[x - 1][y][1]) return true;
    }
    else { // 보
        if (map[x][y - 1][0] || map[x + 1][y - 1][0]) return true;
        if (x > 0 && map[x - 1][y][1] && map[x + 1][y][1]) return true;
    }
    return false;
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    int flen = build_frame.size();
    for (int i = 0; i < flen; i++) {
        vector<int> temp = build_frame[i]; // temp[0~3]
        int x = temp[0], y = temp[1], a = temp[2], b = temp[3];
        if (b == 0) { // 삭제
            map[x][y][a] = 0;
            bool flag = true;
            for (int i = 0; flag && i <= n; i++) for (int j = 0; flag && j <= n; j++)
                    for (int k = 0; flag && k < 2; k++) if (!check(i, j, k, b)) flag = false;
            if (!flag) map[x][y][a] = 1;
        }
        else if (check(x, y, a, b)) map[x][y][a] = 1; // 설치
    }
    
    for (int i = 0; i <= n; i++) for (int j = 0; j <= n; j++) 
        for (int k = 0; k < 2; k++) {
            if (map[i][j][k]) {
                vector <int> v;
                v.push_back(i); v.push_back(j); v.push_back(k);
                answer.push_back(v);
            }
        }
    return answer;
}
