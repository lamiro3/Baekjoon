#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, notRG = 0, RG = 0;
vector<vector<bool>> visited1(101, vector<bool>(101, false));
vector<vector<bool>> visited2(101, vector<bool>(101, false));
vector<vector<char>> Grid(101, vector<char>(101, ' '));

int dirR[4] = { -1, 1, 0, 0 };
int dirC[4] = { 0, 0, -1, 1 };

void BFS(int r, int c, bool isRG) {
	queue<pair<int, int>> q;
	q.push({ r, c });

	if (isRG)
		visited2[r][c] = true;
	else
		visited1[r][c] = true;

	while (!q.empty())
	{
		auto [tr, tc] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = tr + dirR[i];
			int nc = tc + dirC[i];

			if (nr < 1 || nr > N || nc < 1 || nc > N)
				continue;

			if (isRG) {
				if (visited2[nr][nc]) continue;

				if ((Grid[r][c] == 'B' && Grid[nr][nc] == 'B') ||
					(Grid[r][c] != 'B' && Grid[nr][nc] != 'B')) {
					visited2[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
			else {
				if (visited1[nr][nc]) continue;

				if (Grid[r][c] == Grid[nr][nc]) {
					visited1[nr][nc] = true;
					q.push({ nr, nc });
				}
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> Grid[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!visited1[i][j]) {
				BFS(i, j, false);
				notRG++;
			}

			if (!visited2[i][j]) {
				BFS(i, j, true);
				RG++;
			}
		}
	}

	cout << notRG << " " << RG << "\n";

	return 0;
}