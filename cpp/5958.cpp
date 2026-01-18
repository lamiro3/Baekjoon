#include <iostream>
#include <vector>

#define EMPTY '.'
#define ROCK '*'

using namespace std;
int N, ans = 0;
vector<string> field;
vector<vector<bool>> visited;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void DFS(int r, int c) {
// 현재 위치가 field 밖이라면 return
	if (r < 0 || c < 0 || r > N-1 || c > N-1)
		return;

	if (visited[r][c])
		return;
// 방문 처리
	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
// 이동할 곳이 field 밖이거나 ROCK이 아닐 때 PASS
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (nr < 0 || 
			nc < 0 || 
			nr > N-1 || 
			nc > N-1 || 
			field[nr][nc] == EMPTY)
			continue;
// 아직 방문하지 않았다면
		if (!visited[nr][nc])
			DFS(nr, nc);
	}
	return;
}


int main() {
	cin >> N;
	field.resize(N);
	visited.resize(N);
	visited.assign(N, vector<bool>(N, false));

	for (int i = 0; i < N; i++)
		cin >> field[i];
	
	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			if (!visited[r][c] && field[r][c] == ROCK) {
// ROCK 한 덩어리 탐색할 떄 마다 ans += 1
				DFS(r, c);
				ans++;
			}
		}
	}

	cout << ans;

	return 0;
}