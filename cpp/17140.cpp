#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int R = 3, C = 3;
int A[101][101];
/*
	1. 숫자 개수 기준 오름차수 정렬
	2. (1.에서 숫자 등장횟수가 같다면) 숫자 기준 오름차순 정렬
*/
bool compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second;
}

void row_sort() {
	int nextC = 0;

	for (int i = 1; i <= R; i++) {
		int cnt[101] = { 0, };

		for (int j = 1; j <= C; j++) {
			if (A[i][j] != 0) {
				cnt[A[i][j]]++;
			}
		}

		vector <pair<int, int>> info;

		for (int num = 1; num <= 100; num++) {
			if (cnt[num] > 0) {
				info.push_back({ num, cnt[num] });
			}
		}

		sort(info.begin(), info.end(), compare);
		int index = 1;

		for (auto [num, cnt] : info) {
			if (index > 100)
				break;

			A[i][index++] = num;

			if (index > 100)
				break;

			A[i][index++] = cnt;
		}

		nextC = max(nextC, index - 1);

		// 나머지 빈공간 0으로 채우기
		while (index <= 100) {
			A[i][index++] = 0;
		}
	}

	C = min(100, nextC);
}

void col_sort() {
	int nextR = 0;

	for (int j = 1; j <= C; j++){
		int cnt[101] = { 0, };
		for (int i = 1; i <= R; i++) {
			if (A[i][j] != 0) {
				cnt[A[i][j]]++;
			}
		}

		vector <pair<int, int>> info;

		for (int num = 1; num <= 100; num++) {
			if (cnt[num] > 0) {
				info.push_back({ num, cnt[num] });
			}
		}

		sort(info.begin(), info.end(), compare);

		int index = 1;

		for (auto [num, cnt] : info) {
			if (index > 100)
				break;

			A[index++][j] = num;

			if (index > 100)
				break;

			A[index++][j] = cnt;
		}

		nextR = max(nextR, index - 1);

		while(index <= 100) {
			A[index++][j] = 0;
		}
	}

	R = min(100, nextR);
}


int main() {
	int time = 0;
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++){
		vector<int> temp;
		for (int j = 1; j <= 3; j++) {
			cin >> A[i][j];
		}
	}

	while (time <= 100) {
		if (A[r][c] == k && r<=R && c<=C) {
			cout << time;
			return 0;
		}

		if (R >= C) {
			row_sort();
		}
		else {
			col_sort();
		}

		time++;
	}
	
	cout << -1;
	return 0;
}