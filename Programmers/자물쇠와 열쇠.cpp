#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    int M = key.size(), N = lock.size();
    int hcnt = 0;
    for (int i = 0; i< N; i++) for (int j = 0; j < N; j++) if (!lock[i][j]) hcnt++;

    for(int dir = 0; dir < 4; dir++) { // 돌리기
        int rmax = M / 2, rlen = M - 1;
        for(int a = 0; a < rmax; a++, rlen -= 2) {
            int i = 0, tx = a, ty = a;
            int buffer[80] = { 0, }, rear = 0;
            for(i = 0; i < rlen; i++) buffer[rear++] = key[tx][ty++];
            for(i = 0; i < rlen; i++) buffer[rear++] = key[tx++][ty];
            for(i = 0; i < rlen; i++) buffer[rear++] = key[tx][ty--];
            for(i = 0; i < rlen; i++) buffer[rear++] = key[tx--][ty];
            rotate(buffer, buffer + rlen, buffer + rear);
            tx = ty = a;
            rear = 0;
            for(i = 0; i < rlen; i++) key[tx][ty++] = buffer[rear++];
            for(i = 0; i < rlen; i++) key[tx++][ty] = buffer[rear++];
            for(i = 0; i < rlen; i++) key[tx][ty--] = buffer[rear++];
            for(i = 0; i < rlen; i++) key[tx--][ty] = buffer[rear++];
        }

        // 맞추기
        
        for (int sx = -M+1; sx < N; sx++) {
            for (int sy = -M+1; sy < N; sy++) {
                int checker = 0;
                bool flag = true;
                for (int i = 0; flag && i < M; i++) {
                    for (int j = 0; flag && j < M; j++) {
                        int lx = sx + i, ly = sy + j;
                        if (lx < 0 || lx >= N || ly < 0 || ly >= N) continue;
                        else if (lock[lx][ly]) {
                            if (key[i][j]) { flag = false; break; }
                            else continue;
                        }
                        else {
                            if (key[i][j]) checker++;
                            else { flag = false; break; }
                        }
                    }
                }
                if (flag && checker == hcnt) return true;
            }
        }
    }
    
    return false; // key not found
}
