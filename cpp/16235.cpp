#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int N, M, K;
int A[11][11];
int feeds[11][11];
int year = 0;

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

vector<int> Trees[11][11];

// 나이 기준 내림차순 정렬 (나이 어린 나무부터 먹게 하기 위해)
void TreeSort(int r, int c) {
	sort(Trees[r][c].begin(), Trees[r][c].end(), greater<int>());
}

void SS(int r, int c) {
	vector<int> alive; // 살아남은 나무들
	TreeSort(r, c);

	// 나무들 -> 양분 먹기 (봄)
	while (!Trees[r][c].empty()) {
		int age_i = Trees[r][c].back();
		feeds[r][c] -= age_i;

		if (feeds[r][c] < 0) {
			feeds[r][c] += age_i;
			break;
		}

		alive.push_back(age_i + 1);
		Trees[r][c].pop_back();
	}

	// 죽은 나무들 -> 양분으로 (여름)
	while (!Trees[r][c].empty()) {
		// 죽어있으므로 나이 갱신 X
		int age_i = Trees[r][c].back();
		feeds[r][c] += age_i / 2;
		Trees[r][c].pop_back();
	}

	// 살아남은 나무들 (봄)
	for (auto age : alive) {
		Trees[r][c].push_back(age);
	}
	
	return;
}


// 나무들 -> 번식 (가을)
void Autumn(int r, int c) {
	for (int i = 0; i < 8; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];
		if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
			for (auto age : Trees[r][c]) {
				if (age % 5 == 0) {
					Trees[nr][nc].push_back(1);
				}
			}
		}
	}
}

void Winter(int r, int c) {
	feeds[r][c] += A[r][c]; // 겨울
}


int main() {
	ios::sync_with_stdio(false);
    cin.tie(0);

	cin >> N >> M >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
			feeds[i][j] = 5; // 초기 양분은 5
		}
	}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Trees[x][y].push_back(z);
	}

	for (int year = 1; year <= K; year++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				if (!Trees[i][j].empty())
					SS(i, j); // 봄 + 여름
		}

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!Trees[i][j].empty())
					Autumn(i, j); // 가을
				Winter(i, j); // 겨울
			}
		}
	}

	int ans = 0;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			ans += Trees[i][j].size();
		}
	}

	cout << ans << "\n";
	return 0;
}
