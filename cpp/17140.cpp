#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int r, c, k;
vector<pair<int, int>> info(101); // 숫자, 개수
vector<vector<int>> A;

void initinfo() {
	for (int i = 1; i <= 100; i++) {
		info[i].first = i;
		info[i].second = 0;
	}
}


/*
	1. 숫자 개수 기준 오름차수 정렬
	2. (1.에서 숫자 등장횟수가 같다면) 숫자 기준 오름차순 정렬
*/
bool compare(int a, int b) {
	if (info[a].second > info[b].second) {
		return false;
	}

	else if (info[a].second == info[b].second) {
		if (a > b)
			return false;
		else
			return true;
	}

	else
		return true;
}

void row_sort(int row) {
	initinfo();

	for (int j = 0; j < A[row].size(); j++) {
		info[A[row][j]].second++;

	}
	sort(info.begin(), info.end(), compare);

	vector<int> temp;

	for (auto [num, cnt] : info) {
		if (cnt == 0)
			continue;
		temp.push_back(num);
		temp.push_back(cnt);
	}
}

void col_sort(int col) {
	initinfo();
	for (int j = 0; i < j < A.size(); j++) {
		info[A[j][col]].second++;
	}
	sort(info.begin(), info.end(), compare);

	// 열 정렬 방식은 함 생각해봐야할 듯.. 시간 복잡도는 문제 없을 것 같음
}


int main() {
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++){
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		A.push_back(temp);
	}

	if (row >= col) {

	}
}