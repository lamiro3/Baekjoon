#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n, taesoo, p;
	long long points[51];
	cin >> n >> taesoo >> p;

	if (n == 0) {
		cout << 1;
		return 0;
	}

	for (int i = 1; i <= n; i++) {
		cin >> points[i];
	}

	int rank = 1;

	if (taesoo <= points[n] && n == p) {
		cout << -1;
		return 0;
	}

	// 굳이 중복 처리할 필요 없음
	// 어차피 점수가 높은 사람부터 순위를 매기기 때문에, 점수가 같으면 먼저 입력된 사람이 더 높은 순위를 가짐
	for (int i = 1; i <= n; i++) {
		if (points[i] > taesoo)
			rank++;
		else
			break;
	}

	cout << rank;

	return 0;
}