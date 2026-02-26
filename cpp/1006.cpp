#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int T, N, W;
int a[2][10001]; // i행 j열 enemy 수
int dp[10001][3]; // dp[i] : i번째 까지 ( 위: 0, 아래: 1, 위/아래: 2 ) 연결된 경우의 최소 소대 수

void solve(int start) {
    for (int i = start; i <= N; i++) {
        int upperLine = (a[0][i - 1] + a[0][i] <= W) ? 1 : 2;
        int bottomLine = (a[1][i - 1] + a[1][i] <= W) ? 1 : 2;
        int verticalLine = (a[0][i] + a[1][i] <= W) ? 1 : 2;

        dp[i][0] = min(dp[i - 1][1] + upperLine, dp[i - 1][2] + 1);
        dp[i][1] = min(dp[i - 1][0] + bottomLine, dp[i - 1][2] + 1);
        dp[i][2] = min({
            dp[i][0] + 1,
            dp[i][1] + 1,
            dp[i - 1][2] + verticalLine,
            dp[i - 2][2] + upperLine + bottomLine
            });
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> T)) return 0;
    while (T--) {
        cin >> N >> W;
        for (int i = 1; i <= N; i++) cin >> a[0][i];
        for (int i = 1; i <= N; i++) cin >> a[1][i];

        if (N == 1) {
            cout << (a[0][1] + a[1][1] <= W ? 1 : 2) << "\n";
            continue;
        }

        int ans = INF;

        auto init = [&]() {
            for (int i = 0; i <= N; i++)
                for (int j = 0; j < 3; j++)
                    dp[i][j] = INF;

            // i=2일 때 대비해 0 번째 위/아래 모두 연결된 경우 0으로 set
            dp[0][2] = 0;
            };

        // 원형이기 때문에 시작 조건(1번 ~ N번 연결 여부)에 따라 결과 달라짐

        // 1. 원형 연결 없음
        init();
        dp[1][0] = 1;
        dp[1][1] = 1;
        dp[1][2] = (a[0][1] + a[1][1] <= W) ? 1 : 2;
        solve(2);
        ans = min(ans, dp[N][2]);

        // 2. 윗줄만 연결
        if (N > 1 && a[0][1] + a[0][N] <= W) {
            init();
            dp[1][0] = 1; 
            dp[1][1] = 1; 
            dp[1][2] = 2;
            
            //i=2일 때 1번 위와 2번 위가 다시 묶이지 않게 처리
            int tmp = a[0][1]; a[0][1] = INF;
            solve(2);
            ans = min(ans, dp[N][1]);
            a[0][1] = tmp;
        }

        // 3. 아랫줄만 연결
        if (N > 1 && a[1][1] + a[1][N] <= W) {
            init();
            dp[1][0] = 1;
            dp[1][1] = 1;
            dp[1][2] = 2;

            //i=2일 때 1번 아래와 2번 아래가 다시 묶이지 않게 처리
            int tmp = a[1][1]; a[1][1] = INF;
            solve(2);
            ans = min(ans, dp[N][0]);
            a[1][1] = tmp;
        }

        // 4. 위아래 둘 다 연결
        if (N > 1 && a[0][1] + a[0][N] <= W && a[1][1] + a[1][N] <= W) {
            init();
            dp[1][0] = 1;
            dp[1][1] = 1;
            dp[1][2] = 2;

            //i=2일 때 1번 위, 아래와 2번 위, 아래가 다시 묶이지 않게 처리
            int t0 = a[0][1], t1 = a[1][1];
            a[0][1] = a[1][1] = INF;
            solve(2);
            ans = min(ans, dp[N - 1][2]);
            a[0][1] = t0; a[1][1] = t1;
        }

        cout << ans << "\n";
    }
    return 0;
}