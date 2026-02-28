#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int ans = 65;

// 상(0), 우(1), 하(2), 좌(3)
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

// 차례대로 row, column, CCTV type
struct CCTV {
    int r, c, type;
};

vector<CCTV> cctvs;

// CCTV 타입별 가능한 방향 조합
vector<vector<vector<int>>> cctv_dirs = {
    {},
    {{0}, {1}, {2}, {3}},              // 1번
    {{0, 2}, {1, 3}},                  // 2번
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},  // 3번
    {{0, 1, 3}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}}, // 4번
    {{0, 1, 2, 3}}                     // 5번
};

// 해당 방향으로 감시 처리
void watch(vector<vector<int>>& board, int r, int c, int dir) {
    int nr = r + dr[dir];
    int nc = c + dc[dir];

    while (nr >= 0 && nr < N && nc >= 0 && nc < M) {
        if (board[nr][nc] == 6) break; // 벽 만나면 중단
        if (board[nr][nc] == 0) board[nr][nc] = -1; // 감시 구역 표시 (-1로 구분)
        nr += dr[dir];
        nc += dc[dir];
    }
}

void dfs(int cctv_idx, vector<vector<int>> board) {
    // 모든 CCTV의 방향을 결정했다면 사각지대 계산
    if (cctv_idx == cctvs.size()) {
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (board[i][j] == 0) cnt++;
            }
        }
        ans = min(ans, cnt);
        return;
    }

    int r = cctvs[cctv_idx].r;
    int c = cctvs[cctv_idx].c;
    int type = cctvs[cctv_idx].type;

    // 현재 CCTV가 가질 수 있는 모든 방향 조합 시도
    for (auto& dirs : cctv_dirs[type]) {
        vector<vector<int>> next_board = board; // 현재 상태 복사
        for (int d : dirs) {
			watch(next_board, r, c, d); // 해당 방향으로 감시 영역 표시
        }
        dfs(cctv_idx + 1, next_board); // 다음 CCTV로 진행
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    vector<vector<int>> board(N, vector<int>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
            if (board[i][j] >= 1 && board[i][j] <= 5) {
                cctvs.push_back({ i, j, board[i][j] });
            }
        }
    }

    dfs(0, board);
    cout << ans;

    return 0;
}