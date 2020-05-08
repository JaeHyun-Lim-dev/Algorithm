// https://programmers.co.kr/learn/courses/30/lessons/64065?language=cpp
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> varr;
    map<int, int> m;
    int slen = s.size(), cnt = 0;
    for (int i = 1; i < slen - 1; i++) {
        vector<int> v;
        int temp = 0;
        if (s[i] == '{') {
            while (i++) {
                if (s[i] == ',' || s[i] == '}') { v.push_back(temp); temp = 0; }
                else { temp *= 10; temp += s[i] - '0'; }
                if (s[i] == '}') break;
            }
            varr.push_back(v); cnt++;
        }
    }
    for (int i = 1; i <= cnt; i++) {
        for (int j = 0; j < varr.size(); j++) {
            if (varr[j].size() == i) {
                for (int k = 0; k < i; k++) {
                    if (m.find(varr[j][k]) != m.end()) continue;
                    else { m[varr[j][k]] = 1; answer.push_back(varr[j][k]); break; }
                }
            }
        }
    }
    return answer;
}
