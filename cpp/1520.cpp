#include <iostream>
#include <vector>

using namespace std;

int M, N;
int dm[4] = {1, -1, 0, 0};
int dn[4] = { 0, 0, 1, -1 };

vector<vector<long long>> dp, arr;

long long dfs(int m, int n) {
	// 이미 방문(갱신) 된 값이라면 그대로 return
	if (dp[m][n] != -1)
		return dp[m][n];

	dp[m][n] = 0; // 방문 처리(이렇게 되면 방문 불가 구간의 경우의 수 = 0)

	for (int i = 0; i < 4; i++) {
		int sm = m + dm[i];
		int sn = n + dn[i];

		// 가능한 범위 내인지?
		if (1 <= sm && sm <= M && 1 <= sn && sn <= N) {
			// 가능한 이전 위치 (현재 위치보다 arr 값이 더 커야 함)
			if (arr[m][n] < arr[sm][sn]) {
				dp[m][n] += dfs(sm, sn);
			}
		}
	}

	return dp[m][n];
}

int main() {

	cin >> M >> N;
	dp.assign(M+1, vector<long long>(N+1, -1));
	dp[1][1] = 1; // 출발점 경우의 수 = 1

	arr.assign(M + 1, vector<long long>(N + 1, 0));
	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> arr[i][j];
		}
	}

	cout << dfs(M, N);
	return 0;
}