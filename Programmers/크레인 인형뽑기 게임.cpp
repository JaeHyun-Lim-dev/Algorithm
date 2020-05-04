// https://programmers.co.kr/learn/courses/30/lessons/64061
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int stack[1000] = { 0, }, rear = 0, N = board.size();
    for (auto it = moves.begin(); it != moves.end(); it++) {
        int j = *it, i = 0, temp = 0;
        j--;
        for (i = 0; i < N; i++) if (board[i][j]) break;
        if (i < N && board[i][j] > 0) {
            temp = board[i][j];
            board[i][j] = 0;
        }
        if (temp == 0) continue;
        if (rear > 0 && stack[rear - 1] == temp) { rear--; answer += 2; }
        else { stack[rear] = temp; rear++; }
    }
    
    return answer;
}
