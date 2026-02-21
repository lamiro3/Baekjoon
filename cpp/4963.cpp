#include <iostream>
#include <vector>

using namespace std;

int w, h;

int dx[8] = { 1, -1, 0, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 0, 1, -1, 1, -1, 1, -1};

vector<vector<int>> sq;
vector<vector<bool>> visited;

void dfs(int x, int y) {
	visited[x][y] = true;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < h && 0 <= ny && ny < w) {
			if (!visited[nx][ny] && sq[nx][ny] == 1)
				dfs(nx, ny);
		}
	}
}

int main() {
	while (1) {
		int ans = 0;

		cin >> w >> h;

		if (w == 0 && h == 0)
			return 0;

		sq.assign(h, vector<int>(w, 0));
		visited.assign(h, vector<bool>(w, false));

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> sq[i][j];
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (!visited[i][j] && sq[i][j] == 1) {
					ans++;
					dfs(i, j);
				}
			}
		}

		cout << ans << endl;
	}
}