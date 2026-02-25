#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 1e9;
int N, W;
int e[2][10005];
int dp[10005][3];

// dp[i][0]: i번째 열의 위쪽만 채워짐
// dp[i][1]: i번째 열의 아래쪽만 채워짐
// dp[i][2]: i번째 열의 위/아래 모두 채워짐

void solve(int start) {
    for (int i = start; i <= N; i++) {
        // 1. i번째 열의 위/아래를 각각 1개씩 혹은 세로 1개로 채우는 경우
        dp[i][2] = dp[i - 1][2] + (e[0][i] + e[1][i] <= W ? 1 : 2);

        // 2. i-1열과 i열의 위쪽을 가로로 연결하는 경우
        if (i > 1 && e[0][i - 1] + e[0][i] <= W) {
            dp[i][0] = dp[i - 1][1] + 1;
        }
        else {
            dp[i][0] = dp[i - 1][2] + 1;
        }

        // 3. i-1열과 i열의 아래쪽을 가로로 연결하는 경우
        if (i > 1 && e[1][i - 1] + e[1][i] <= W) {
            dp[i][1] = dp[i - 1][0] + 1;
        }
        else {
            dp[i][1] = dp[i - 1][2] + 1;
        }

        // 4. 위/아래 모두 가로로 연결되어 i열이 완성되는 경우
        if (i > 1) {
            dp[i][2] = min(dp[i][2], min(dp[i][0] + 1, dp[i][1] + 1));
            if (e[0][i - 1] + e[0][i] <= W && e[1][i - 1] + e[1][i] <= W) {
                int prev2 = (i > 2) ? dp[i - 2][2] : 0;
                dp[i][2] = min(dp[i][2], prev2 + 2);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> W;
        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                cin >> e[i][j];

        if (N == 1) {
            cout << (e[0][1] + e[1][1] <= W ? 1 : 2) << "\n";
            continue;
        }

        int ans = INF;

        for (int i = 0; i <= N; i++) 
            dp[i][0] = dp[i][1] = dp[i][2] = INF;

        dp[0][2] = 0;

        // Case 1: 아무 연결 없음
        solve(1);
        ans = min(ans, dp[N][2]);

        // Case 2: 1번-N번 위쪽 가로 연결
        if (e[0][1] + e[0][N] <= W) {
            for (int i = 0; i <= N; i++) 
                dp[i][0] = dp[i][1] = dp[i][2] = INF;
            dp[1][0] = 1;
            dp[1][1] = (e[1][1] > 0) ? 2 : 1; // 1번 아래는 단독 배치
            dp[1][2] = 2;
            solve(2);
            ans = min(ans, dp[N][1]);
        }

        // Case 3: 1번-N번 아래쪽 가로 연결
        if (e[1][1] + e[1][N] <= W) {
            for (int i = 0; i <= N; i++) 
                dp[i][0] = dp[i][1] = dp[i][2] = INF;
            dp[1][1] = 1;
            dp[1][0] = (e[0][1] > 0) ? 2 : 1; // 1번 위는 단독 배치
            dp[1][2] = 2;
            solve(2);
            ans = min(ans, dp[N][0]);
        }

        // Case 4: 1번-N번 위/아래 모두 가로 연결
        if (e[0][1] + e[0][N] <= W && e[1][1] + e[1][N] <= W) {
            for (int i = 0; i <= N; i++) 
                dp[i][0] = dp[i][1] = dp[i][2] = INF;
            dp[1][2] = 2;
            solve(2);
            ans = min(ans, dp[N - 1][2]);
        }

        cout << ans << "\n";
    }
    return 0;
}