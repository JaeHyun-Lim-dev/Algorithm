// https://programmers.co.kr/learn/courses/30/lessons/64062
#include <string>
#include <vector>
#include <queue>
using namespace std;
struct ST {
    int idx, num;
};

bool operator <(ST s1, ST s2) {
    if (s1.num == s2.num) return s1.idx > s2.idx;
    else return s1.num < s2.num;
}

int solution(vector<int> stones, int k) {
    int answer = 200000001;
    priority_queue<ST> pq;
    for (int i = 0; i < stones.size(); i++) {
        pq.push({i, stones[i]});
        if (pq.size() < k) continue;
        while (pq.top().idx + k - 1 < i) pq.pop();
        if (answer > pq.top().num) answer = pq.top().num;
    }
    return answer;
}
