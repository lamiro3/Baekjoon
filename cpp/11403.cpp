#include <iostream>
#include <queue>

using namespace std;

vector<vector<int>> G;
int N;

int isPossible(int a, int b) {
	queue<pair<int, int>> q;
	vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));

	for (int i = 1; i <= N; i++) {
		if (G[a][i]) {
			q.push({ a, i });
		}
	}

	while (!q.empty()) {
		auto[r, c] = q.front();
		q.pop();
		visited[r][c] = true;

		if (c == b)
			return 1;

		for (int i = 1; i <= N; i++) {
			if (G[c][i] && !visited[c][i]) {
				q.push({ c, i });
			}
		}
	}

	return 0;
}

int main() {
	cin >> N;
	G.assign(N+1, vector<int>(N+1, 0));

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> G[i][j];
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << isPossible(i, j) << " ";
		}
		if (i < N)
			cout << endl;
	}

	return 0;
}