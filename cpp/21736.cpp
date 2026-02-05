#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define O 'O'
#define X 'X'
#define I 'I'
#define P 'P'

using namespace std;

int N, M, sx, sy, ans = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

vector<string> grid(600);
bool visited[600][600] = { {false, }, };

void BFS(int sx, int sy) {
	queue<pair<int, int>> q;
	q.push({ sx, sy });
	visited[sx][sy] = true;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (grid[x][y] == P)
			ans++;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((0 <= nx && nx < N) && (0 <= ny && ny < M)) {
				if (grid[nx][ny] != X && !visited[nx][ny])
					q.push({ nx, ny });
					visited[nx][ny] = true;
			}
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string g;
		cin >> g;

		for (int j = 0; j < M; j++) {
			if (g[j] == I) {
				sx = i;
				sy = j;
				break;
			}
		}

		grid[i] = g;
	}

	BFS(sx, sy);
	
	if (ans == 0)
		cout << "TT";
	else
		cout << ans;

	return 0;
}