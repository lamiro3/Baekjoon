#include <iostream>
#include <vector>
#include <queue>
#define MAX_VALUE 90000
using namespace std;

int n, sx, sy, ex, ey;
int dx[8] = { 1, 1, 2, 2, -1, -1, -2, -2 };
int dy[8] = { 2, -2, 1, -1, 2, -2, 1, -1 };

void bfs() {
	vector<vector<bool>> visited(301, vector<bool>(301, false));
	vector<vector<int>> ans(301, vector<int>(301, MAX_VALUE));
	queue<pair<int, int>> q;

	q.push({ sx, sy });
	ans[sx][sy] = 0;
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (x == ex && y == ey) {
			cout << ans[x][y] << endl;
			return;
		}
		
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < n) {
				if (!visited[nx][ny]) {
					visited[nx][ny] = true;
					q.push({ nx, ny });
					ans[nx][ny] = min(ans[x][y] + 1, ans[nx][ny]);
				}
			}
		}

	}
}

int main() {
	int t;
	cin >> t;

	while (t--) {
		cin >> n;
		cin >> sx >> sy >> ex >> ey;

		bfs();
	}
	return 0;
}