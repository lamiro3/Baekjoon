#include <iostream>

using namespace std;

int N, H, M;

// 3보다 크면 -1 처리..
int ans = 4;

// ladder[r][c]: 가로선 r ~ 세로선 c -> c+1의 연결 여부
bool ladder[31][11];

bool check() {
	for (int start = 1; start <= N; start++) {
		int c = start;
		for (int r = 1; r <= H; r++) {
			if (ladder[r][c])
				c++; // 연결되어있으면 오른쪽으로 이동
			else if (c > 1 && ladder[r][c - 1])
				c--; // 연결되어있으면 왼쪽으로 이동
		}
		if (start != c) return false;
	}

	return true;
}

void DFS(int d, int r, int c) {
	// 이미 ans 보다 같거나 크다면 굳이 진행할 필요 없으므로
	if (d >= ans)
		return;

	// i to i 모두 만족했다면 최소 개수 갱신
	if (check()) {
		ans = min(ans, d);
		return;
	}

	if (d == 3)
		return;

	for (int r = 1; r <= H; r++) {
		for (int c = 1; c < N; c++) {
			if (ladder[r][c]) // c -> c+1 이미 연결됐다면 
				continue;

			if (c > 1 && ladder[r][c - 1]) // c -> c-1 연결됐다면 (연속 연결은 불가능하므로)
				continue;

			if (ladder[r][c + 1]) // c+1 -> c+2 연결됐다면 (연속 연결은 불가능하므로)
				continue;

			// 임시 갱신
			ladder[r][c] = true;
			DFS(d + 1, r, c);
			// 원상 복구
			ladder[r][c] = false;
		}
	}
}

int main() {
	cin >> N >> M >> H;

	// 연결 처리
	for (int i=0; i< M; i++) {
		int a, b;
		cin >> a >> b;
		ladder[a][b] = true;
	}

	DFS(0, 1, 1);
	cout << ((ans == 4) ? -1 : ans);
	return 0;
}