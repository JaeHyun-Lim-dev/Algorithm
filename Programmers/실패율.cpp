// https://programmers.co.kr/learn/courses/30/lessons/42889
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct ST {
    int snum;
    int a, b;
    double ratio;
};

bool compare(ST s1, ST s2) {
    if (s1.ratio == 0) {
        if (s2.ratio == 0) return s1.snum < s2.snum;
        else return false;
    }
    if (s2.ratio == 0) {
        if (s1.ratio == 0) return s1.snum < s2.snum;
        else return true;
    }
    if (s1.ratio != s2.ratio) return s1.ratio > s2.ratio;
    else return s1.snum < s2.snum;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int a[502] = { 0, };
    int b[502] = { 0, };
    int slen = stages.size();
    for (int i = 0; i < slen; i++) {
        int ts = stages[i];
        for (int j = 1; j <= ts; j++) b[j]++;
        a[ts]++;
    }
    ST temp;
    vector<ST> v;
    for (int i = 1; i <= N; i++) {
        temp = { i, a[i], b[i], 0 };    
        if (b[i] == 0) { temp.b = i; temp.a = 0; temp.ratio = 0;}
        else temp.ratio = ((double)a[i]/(double)b[i]);
        v.push_back(temp);
    }
    
    sort(v.begin(), v.end(), compare);
    for (auto it = v.begin(); it != v.end(); it++) answer.push_back(it->snum);
    
    return answer;
}
