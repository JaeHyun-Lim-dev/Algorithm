// https://programmers.co.kr/learn/courses/30/lessons/64063
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long int ll;
map<ll, ll>m;

ll find(ll idx) {
    if (m.find(idx) != m.end()) {
        return m[idx] = find(m[idx] + 1);
    }
    else return m[idx] = idx;
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;
    for (int i = 0; i < room_number.size(); i++) {
        answer.push_back(find(room_number[i]));
    }
    
    return answer;
}
