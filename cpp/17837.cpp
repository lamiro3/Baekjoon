#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Horse {
    int x, y, d;
};

int n, k;
int grid[13][13];
vector<int> board[13][13];
Horse horse[11];

// 우 좌 상 하
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

int reverseDir(int d) {
    if (d == 0) return 1;
    if (d == 1) return 0;
    if (d == 2) return 3;
    return 2;
}

int main() {
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> grid[i][j];

    for (int i = 1; i <= k; i++) {
        int x, y, d;
        cin >> x >> y >> d;

        horse[i] = { x, y, d - 1 };
        board[x][y].push_back(i);
    }

    for (int turn = 1; turn <= 1000; turn++) {

        for (int i = 1; i <= k; i++) {

            int x = horse[i].x;
            int y = horse[i].y;
            int d = horse[i].d;

            int nx = x + dx[d];
            int ny = y + dy[d];

            // 범위 밖 or 파란색
            if (nx < 1 || ny < 1 || nx > n || ny > n || grid[nx][ny] == 2) {

                d = reverseDir(d);
                horse[i].d = d;

                nx = x + dx[d];
                ny = y + dy[d];

                if (nx < 1 || ny < 1 || nx > n || ny > n || grid[nx][ny] == 2)
                    continue;
            }

            vector<int>& cur = board[x][y];

            int idx = find(cur.begin(), cur.end(), i) - cur.begin();

			// 이동할 말과 그 위에 있는 말들을 떼어냄
            vector<int> moving(cur.begin() + idx, cur.end());
            cur.erase(cur.begin() + idx, cur.end());

			// 빨간색이면 이동할 말들의 순서를 뒤집음
            if (grid[nx][ny] == 1)
                reverse(moving.begin(), moving.end());

            for (int m : moving) {
                board[nx][ny].push_back(m);
                horse[m].x = nx;
                horse[m].y = ny;
            }

            if (board[nx][ny].size() >= 4) {
                cout << turn << "\n";
                return 0;
            }
        }
    }

    cout << -1 << "\n";
    return 0;
}