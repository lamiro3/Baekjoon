#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int lab[51][51];
int init[51][51];

// 0: 빈 칸, 1: 벽, 2: 비활성화된 바이러스, 3: 활성화된 바이러스

int N, M;
int ans = 2501;

vector<pair<int, int>> virus;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int BFS(vector<pair<int, int>> temp) {
	int time = 0;
	queue<tuple<int, int, int>> q;

	for (auto [x, y] : temp) {
		lab[x][y] = 3; // 바이러스 활성화
		q.push({ x, y, 0 });
	}

	while (!q.empty()) {
		auto [cx, cy, ct] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			// 범위를 벗어나거나 벽이면 넘어감
			if (nx < 1 || nx > N || ny < 1 || ny > N)
				continue;

			if (lab[nx][ny] == 1 || lab[nx][ny] == 3)
				continue;

			else if (lab[nx][ny] == 2) {
				lab[nx][ny] = 3;
				q.push({ nx, ny, ct + 1 });
			}
				
			else { // 빈 칸일 때만 시간 갱신해야 함
				lab[nx][ny] = 3;
				q.push({ nx, ny, ct + 1 });
				time = max(time, ct + 1);
			}
		}
	}

	return time;
}

void initLab() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			lab[i][j] = init[i][j];
		}
	}
}

void solve(int now, vector<pair<int, int>> temp) {
	// M개 바이러스 조합이 완성됐다면
	if (temp.size() == M) {
		int time = BFS(temp);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (lab[i][j] == 0) {
					// 바이러스가 퍼지지 못한 곳이 있다면
					initLab();
					return;
				}
			}
		}
		// 모든 곳에 바이러스가 잘 퍼졌다면 최소 시간 갱신
		ans = min(ans, time);
		initLab();
		return;
	}

	if (now == virus.size())
		return;

	// 바이러스 활성 위치 조합 생성
	solve(now + 1, temp);
	temp.push_back(virus[now]);
	solve(now + 1, temp);
}

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= N; j++) {
			int temp;
			cin >> temp;
			lab[i][j] = temp;
			init[i][j] = temp;
			
			// 바이러스 위치 저장
			if (temp == 2)
				virus.push_back({ i, j });
		}
	}

	solve(0, vector<pair<int, int>>());

	cout << (ans == 2501 ? -1 : ans);

	return 0;
}