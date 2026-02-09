#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int sr, sc;
vector<vector<int>> grid; // 입력
vector<vector<int>> ans;  // 출력
vector<vector<bool>> visited; // 방문 처리용

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

void BFS(int sr, int sc) {
	queue<pair<int, int>> q;

	// 출발 위치
	q.push({ sr, sc });
	visited[sr][sc] = true;

	while (!q.empty()) {
		auto [r, c] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];
			
			if (0 <= nr && nr < n && 0 <= nc && nc < m) {
				// 다음 위치 이미 방문했거나 or 방문 불가능할 경우
				if (ans[nr][nc] != 0 || grid[nr][nc] == 0) {
					visited[nr][nc] = true;
					continue;
				}

				// 아직 방문하지 않았다면
				if (!visited[nr][nc]) {
					q.push({ nr, nc });
					visited[nr][nc] = true;
					ans[nr][nc] = ans[r][c] + 1;
				}
			}
		}
	}
}


int main() {
	cin >> n >> m;

	grid.assign(n, vector<int>(m, 0));
	ans.assign(n, vector<int>(m, 0));
	visited.assign(n, vector<bool>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int input;
			cin >> input;
			grid[i][j] = input;
			if (input == 2) {
				sr = i;
				sc = j;
			}
		}
	}

	BFS(sr, sc);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// 방문 가능한 구역인데 방문하지 못했면
			/* (ex)
					0 0 0
					0 1 0
					0 0 0
			*/
			if (grid[i][j] == 1 && !visited[i][j])
				cout << -1;
			else cout << ans[i][j];

			if (j < m - 1)
				cout << " ";
		}
		cout << endl;
	}

	return 0;
}