#include <iostream>
#include <vector>

using namespace std;

int board[101][101];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

int main() {
    int N;
    cin >> N;
    while (N--) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        vector<int> dirs;
        dirs.push_back(d); // 0세대 방향

        // g세대까지 방향 정보 생성
        for (int i = 0; i < g; i++) {
            for (int j = dirs.size() - 1; j >= 0; j--) {
                dirs.push_back((dirs[j] + 1) % 4); // 역순으로 꺼내서 +1 (반시계 90도)
            }
        }

        board[x][y] = 1;

        // 방문 처리
        for (int dir : dirs) {
            x += dx[dir];
            y += dy[dir];
            // 문제 똑바로 봐라 ㅋㅋㅋㅋ
            if (x >= 0 && x <= 100 && y >= 0 && y <= 100) {
                board[x][y] = 1;
            }
        }
    }

    // 사각형 개수
    int cnt = 0;

    /* 
        범위에 음수도 포함되는 줄 알고 map으로 접근하는 바보 행동을 했었음
        100행 100열이라 충분히 O(N^2)로 풀 수 있는 문제
    */
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (board[i][j] && board[i + 1][j] && board[i][j + 1] && board[i + 1][j + 1]) {
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}