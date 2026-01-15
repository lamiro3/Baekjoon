#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>

using namespace std;

int N, L, R, ans = 0, cnt, sum; // 정답, (매일) 연합 내 국가 수, (매일) 연합 내 국가들의 인구 합
vector<vector<int>> A(51, vector<int>(51, 0)); // 1 <= N <= 50
bool visited[51][51] = { {false, }, };

queue<pair<int, int>> group; // 매일 같은 연합에 있는 국가 저장용도

// 탐색 시 이동 방향
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void BFS(int r, int c) {
	queue<pair<int, int>> q;

	// 시작점 처리
	q.push({ r, c });
	visited[r][c] = true;
	group.push({ r, c });
	cnt++;
	sum += A[r][c];

	while (!q.empty()) {
		auto [tr, tc] = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			// 이동할 위치
			int nr = tr + dr[i];
			int nc = tc + dc[i];

			if (nr < 1 || nr > N || nc < 1 || nc > N)
				continue; // 범위 밖일 경우 넘어감

			if (visited[nr][nc]) continue; // (ans) day에 방문했다면 넘어감

			int delta = abs(A[nr][nc] - A[tr][tc]); // 근접 국가간의 인구 수 차이

			if (L <= delta && delta <= R) { // 범위 내에 있다면 연합에 추가
				q.push({ nr, nc });
				visited[nr][nc] = true;
				group.push({ nr, nc });
				cnt++;
				sum += A[nr][nc];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> L >> R;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	while (1) {
		bool isChanged = false;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j]) {
					BFS(i, j);
					if (cnt > 1) { // 연합이 존재한다면 * (cnt = 1일 경우 연합이 아니므로)
						isChanged = true;
						int avg = sum / cnt;
						while (!group.empty()) {
							auto [r, c] = group.front();
							group.pop();
							A[r][c] = avg; // 연합 내 국가들의 인구 이동 진행
						}
					}
					else // 연합이 존재하지 않는다면 group에 있는 국가 비우기(초기화) ~ 아직 조사하지 않은 곳에 다른 연합이 존재할 수 있기 때문
						while (!group.empty()) 
							group.pop();
					cnt = 0;
					sum = 0;
				}
			}
		}

		if (!isChanged) // 국경선 열린 적 없었다면 마감
			break;

		// 열린 적 있었다면 ans++, visited와 isChanged 초기화
		ans++;
		memset(visited, false, sizeof(visited));
		isChanged = false;
	}
		
	std::cout << ans;

	return 0;
}