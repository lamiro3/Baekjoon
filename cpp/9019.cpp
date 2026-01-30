#include <iostream>
#include <vector>
#include <queue>

using namespace std;

queue<pair<int, string>> q;

void BFS(int tgt) {
	vector<bool> visited(10000, false);

	while (!q.empty()) {
		auto [num, oper] = q.front();
		q.pop();

		// 이미 방문했다면 PASS
		if (visited[num])
			continue;

		// 방문 처리
		visited[num] = true;

		// tgt에 도달했을 경우 출력
		if (num == tgt) {
			cout << oper << endl;
			return;
		}

		// 0이상 10000 미만이기 때문에 수식 유도할 수 있음
		int D = (2 * num) % 10000;
		int S = (num == 0) ? 9999 : num - 1;
		int L = (num % 1000) * 10 + (num / 1000);
		int R = (num / 10) + (num % 10) * 1000;

		// 다음 탐색을 위해 큐에 추가
		q.push({ D, oper + "D" });
		q.push({ S, oper + "S" });
		q.push({ L, oper + "L" });
		q.push({ R, oper + "R" });
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	while (T--) {
		int A, B;
		cin >> A >> B;
		
		q.push({ A, "" });
		BFS(B);
		
		while (!q.empty())
			q.pop();
	}
}