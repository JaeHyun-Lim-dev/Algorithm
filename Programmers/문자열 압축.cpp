// https://programmers.co.kr/learn/courses/30/lessons/60057
#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int slen = s.length();
    int answer = slen;
    int i = 0;
    int tRes = 0;
    for (int k = 1; k <= (slen / 2); k++) {
        tRes = 0;
        i = 0;
        string temp = s.substr(i, k);
        int flag = 0;
        while (i + k  <= slen) {
            string ns = s.substr(i+k, k);
            if (temp == ns) {
                if(!flag) flag++;
                flag++;
            }
            else {
                int flen = 0;
                while (flag > 0) {
                    flag /= 10;
                    flen++;
                }
                tRes += (k + flen);               
                temp = ns;
                flag = 0;
            }
            i += k;
        }
        if (i+k > slen) tRes += (slen - i);
        answer = (tRes < answer)? tRes : answer;
    }
    return answer;
}
