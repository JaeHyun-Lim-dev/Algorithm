// https://programmers.co.kr/learn/courses/30/lessons/42888
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer, elcres, uidres;
    map<string, string> m; // m[uid] = nickname
    int rlen = record.size();
    for (int i = 0; i < rlen; i++) {
        string r = record[i];
        int s = -1, ulen = 0;
        for (int j = 0; j < r.length(); j++) {
            if (r[j] == ' ') {
                if (s == -1) s = j;
                else break;
                ulen = 0;
            }
            ulen++;
        }
        string uid = r.substr(s, ulen);
        if (r[0] == 'E') {
            m[uid] = r.substr(s + ulen + 1, 100);
            elcres.push_back("님이 들어왔습니다.");
            uidres.push_back(uid);
        }
        else if (r[0] == 'L') {
            elcres.push_back("님이 나갔습니다.");
            uidres.push_back(uid);
        }
        else if (r[0] == 'C') {
            m[uid] = r.substr(s + ulen + 1, 100);
        }
    }
    
    for (int i = 0; i < elcres.size(); i++) {
        string uname = m[uidres[i]];
        answer.push_back(uname.append(elcres[i]));
    }
    return answer;
}
