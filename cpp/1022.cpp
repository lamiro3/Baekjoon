#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

#define max(a, b) (a) > (b) ? (a) : (b)

using namespace std;

int abs(int x) {
	return (x > 0) ? x : -x;
}

int value(int r, int c) { // 각 좌표별 값 점화식 이용
	int b = max(abs(r), abs(c));
	int MAX = (2 * b + 1) * (2 * b + 1);

	if (r == b) {
		if (c == b) return MAX;
		else return MAX + c - b;
	}

	else if (r == -b) return MAX - 5 * b - c;
	else if (c == b) return MAX - 7 * b - r;
	else if (c-- - b) return MAX - 3 * b + r;
}

int main() {
	int r1, r2, c1, c2;
	cin >> r1 >> c1 >> r2 >> c2;
	
	int R = r2 - r1 + 1;
	int C = c2 - c1 + 1;

	long maxValue = 0;

	vector<vector<int>> answer(R, vector<int>(C, 0));

	for (int i = r1; i < r2 + 1; i++) {
		for (int j = c1; j < c2 + 1; j++) {
			int val = value(i, j);
			answer[i - r1][j - c1] = val;
			maxValue = max(maxValue, val);
		}
	}

	int digits = (int)log10(maxValue) + 1; // 가장 큰 값의 자리수 계산 위해 ans 저장 후 요청한 format에 맞게 출력

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			std::cout << setw(digits) << setfill(' ') << answer[i][j];
			if (j != C-1) cout << " ";
		}
		cout << "\n";
	}

	return 0;
}