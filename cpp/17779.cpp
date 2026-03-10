#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N;
int A[21][21];
int totalSum = 0;
int ans = 1e8;

void solve(int x, int y, int d1, int d2) {
    // 5번 구역의 경계선을 체크하기 위한 배열
    bool isBoundary[21][21] = { false };

    // 1. 5번 구역 경계선 표시
    for (int i = 0; i <= d1; i++) {
        isBoundary[x + i][y - i] = true;           // (1)
        isBoundary[x + d2 + i][y + d2 - i] = true; // (4)
    }
    for (int i = 0; i <= d2; i++) {
        isBoundary[x + i][y + i] = true;           // (2)
        isBoundary[x + d1 + i][y - d1 + i] = true; // (3)
    }

    int sum[6] = { 0 };

    // 2. 1번 선거구
    for (int r = 1; r < x + d1; r++) {
        for (int c = 1; c <= y; c++) {
            if (isBoundary[r][c]) break; // 경계선을 만나면 해당 행은 종료
            sum[1] += A[r][c];
        }
    }

    // 3. 2번 선거구
    for (int r = 1; r <= x + d2; r++) {
        for (int c = N; c > y; c--) { // 오른쪽에서 왼쪽으로 오다가 경계선 만나면 종료
            if (isBoundary[r][c]) break;
            sum[2] += A[r][c];
        }
    }

    // 4. 3번 선거구
    for (int r = x + d1; r <= N; r++) {
        for (int c = 1; c < y - d1 + d2; c++) {
            if (isBoundary[r][c]) break;
            sum[3] += A[r][c];
        }
    }

    // 5. 4번 선거구
    for (int r = x + d2 + 1; r <= N; r++) {
        for (int c = N; c >= y - d1 + d2; c--) {
            if (isBoundary[r][c]) break;
            sum[4] += A[r][c];
        }
    }

    // 6. 5번 선거구 (전체에서 1~4번 합을 뺌)
    sum[5] = totalSum - (sum[1] + sum[2] + sum[3] + sum[4]);

    // 최댓값과 최솟값의 차이 계산
    int maxPop = 0, minPop = 1e8;
    for (int i = 1; i <= 5; i++) {
        maxPop = max(maxPop, sum[i]);
        minPop = min(minPop, sum[i]);
    }
    ans = min(ans, maxPop - minPop);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
            totalSum += A[i][j];
        }
    }

    // 가능한 모든 x, y, d1, d2 탐색
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            for (int d1 = 1; d1 <= N; d1++) {
                for (int d2 = 1; d2 <= N; d2++) {
                    // 문제에서 제시한 기준에 부합하는지 체크
                    if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {
                        solve(x, y, d1, d2);
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}