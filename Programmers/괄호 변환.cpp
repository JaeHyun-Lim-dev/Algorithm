// https://programmers.co.kr/learn/courses/30/lessons/60058
#include <string>
#include <vector>
using namespace std;

string modify(int s, int e, string p) {
    string res = "";
    if (s >= e) return res;
    int lp = 0, rp = 0, top = 0, i;
    bool flag = true;
    for (i = s; i < e; i++) {
        if (p[i] == '(') { lp++; top++; }
        else { rp++; top--; if (top < 0) flag = false; }
        if (lp == rp) break;
    }
    if (flag) {
        res.append(p.substr(s, lp + rp));
        res.append(modify(i + 1, e, p));
        return res;
    }
    else {
        res.append("(");
        res.append(modify(i + 1, e, p));
        res.append(")");
        for (int j = s + 1; j < i; j++) {
            if (p[j] == '(') res.append(")");
            else res.append("(");
        }
        return res;
    }
}

string solution(string p) {
    string answer = "";
    answer.append(modify(0, p.length(), p));
    return answer;
}
