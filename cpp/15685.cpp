#include <iostream>
#include <map>
#include <vector>
#define point pair<int, int>

using namespace std;
typedef map<point, pair<point, bool>> Map;

/*
1. 오른쪽 위
=> 0, 1
2. (왼쪽 위)
=> [0, 1], (2, 1)
3. 왼쪽, 아래, (왼쪽, 위)
=> [0, 1, 2, 1], 2, 3, (2, 1)
4. 왼쪽, 아래, 오른쪽, 아래, (왼쪽, 아래, 왼쪽, 위)
=> [0, 1, 2, 1, 2, 3, 2, 1], 2, 3, 0, 3, (2, 3, 2, 1)
5. 왼쪽, 아래, 오른쪽, 아래, 오른쪽, 위, 오른쪽, 아래, (왼쪽, 아래, 오른쪽, 아래, 왼쪽, 아래, 왼쪽, 위)
*/

int N;
Map grid;
Map sq;

// 오른쪽부터 시작해 반시계방향
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, -1, 0, 1 };

void SqCheck(point start) {
	int x = start.first;
	int y = start.second;
	
	int d2x[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
	int d2y[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
	bool isThere[8] = { false, };

	for (int i = 0; i < 8; i++) {
		int nx = x + d2x[i];
		int ny = y + d2y[i];

		if (grid[{nx, ny}].second)
			isThere[i] = true;
		else
			isThere[i] = false;
	}

	// 현재 위치 기준 우 상단 
	if (isThere[0] && isThere[1] && isThere[2]) {
		sq[{x, y}].first = { x, y };
		sq[{x, y}].second = true;
	}

	// 우 하단
	else if (isThere[2] && isThere[3] && isThere[4]) {
		sq[{x, y+1}].first = { x, y+1 };
		sq[{x, y + 1}].second = true;
	}

	// 좌 하단
	else if (isThere[4] && isThere[5] && isThere[6]) {
		sq[{x-1, y+1}].first = { x-1, y+1 };
		sq[{x - 1, y + 1}].second = true;
	}

	// 좌 상단
	else if (isThere[6] && isThere[7] && isThere[0]) {
		sq[{x-1, y}].first = { x-1, y };
		sq[{x - 1, y}].second = true;
	}
}

void GenDragon(point start, int init_dir, int gen) {
	vector<int> history;
	int size = 0;

	for (int i = 0; i <= gen; i++) {
		if (i == 0) {
			history.push_back(init_dir);
			size++;
		}

		else if (i == 1) {
			history.push_back((init_dir + 1) % 4);
			size *= 2;
		}

		else {
			for (int j = 0; j < size; j++) {
				history.push_back((history[j] + 2) % 4);
			}

			for (int j = 0; j < size; j++) {
				history.push_back(history[j+size]);
			}

			size *= 2;
		}
	}

	int nx = start.first;
	int ny = start.second;
	grid[start].first = start;
	grid[start].second = true;

	for (auto dir : history) {
		nx += dx[dir];
		ny += dy[dir];
		grid[{nx, ny}].first = { nx, ny };
		grid[{nx, ny}].second = true;
	}
}

int main() {
	cin >> N;

	while (N--) {
		// 시작점, 시작 방향, 세대
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		GenDragon({ x, y }, d, g);
		cout << "gen is Done" << "\n";
	}

	for (auto g: grid) {
		auto [p, isThere] = g.second;
		//cout << p.first << ", " << p.second << "\n";
		SqCheck(p);
	}

	for (auto k : sq) {
		auto [p, isThere] = k.second;
		cout << p.first << p.second << "\n";
	}

	return 0;
}