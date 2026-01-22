#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M, ans = 0;
vector<vector<int>> arr;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, -1, 0, 1 };

// ㅗ 모양 제외 테트로미노 처리
void Find(int r, int c, int prev, int sum, int cnt) {
	if (cnt == 4) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
// 바로 직전 위치로 못 돌아가게끔 처리
		if (cnt > 1 && dr[prev] == -dr[i] && dc[prev] == -dc[i])
			continue;

		int nr = r + dr[i];
		int nc = c + dc[i];

		if (0 <= nr && nr < N && 0 <= nc && nc < M)
			Find(nr, nc, i, sum + arr[nr][nc], cnt + 1);
	}
	return;
}

int main() {
	cin >> N >> M;
	arr.assign(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < M; c++) {
// ㅗ 모양 제외 테트로미노 처리
			Find(r, c, -1, arr[r][c], 1);
			
// ㅗ 모양 테트로미노 처리
			int cnt = 0, sum = arr[r][c];

			for (int i = 0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];

				if (0 <= nr && nr < N && 0 <= nc && nc < M) {
					cnt++;
					sum += arr[nr][nc];
				}
			}

// 기준점으로부터 동서남북 중 3가지 이동 가능 ~ 기준점 포함 합으로 갱신
			if (cnt == 3)
				ans = max(ans, sum);

// 기준점으로부터 4방향 모두 이동 가능 ~ {총 5개 합} - {각 방향 별 값}으로 갱신
			else if (cnt == 4)
				ans = max({ ans,
					sum - arr[r + 1][c], // ㅗ 모양
					sum - arr[r][c + 1], // ㅓ 모양
					sum - arr[r - 1][c], // ㅜ 모양
					sum - arr[r][c - 1] }); // ㅏ 모양
		}
	}

	cout << ans;

	return 0;
}