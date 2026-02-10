#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int N, M;
vector<int> ladder(101, -1);
vector<int> snake(101, -1);
vector<bool> visited(101, false);

int find() {
	queue<pair<int, int>> q;
	q.push({1, 0});
	visited[1] = true;

	while (!q.empty()) {
		auto[now, cnt] = q.front();
		q.pop();

		// 첫 100 도달 case = 최소 이동 case
		if (now == 100)
			return cnt;

		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next > 100) continue;

			// 사다리가 존재한다면
			if (ladder[next] != -1)
				next = ladder[next];

			// 뱀이 존재 한다면
			else if (snake[next] != -1)
				next = snake[next];

			if (!visited[next]) {
				visited[next] = true;
				q.push({ next, cnt + 1 });
			}
		}
	}
}

int main() {
	cin >> N >> M;

	while (N--) {
		int x, y;
		cin >> x >> y;
		ladder[x] = y;
	}

	while (M--) {
		int u, v;
		cin >> u >> v;
		snake[u] = v;
	}

	cout << find();

	return 0;
}