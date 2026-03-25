#include <iostream>
#define NULL -1

using namespace std;

typedef struct Cnum {
	int val;
	bool isDel;
} Cnum;

int n, m, t, ans = 0;
Cnum circle[50][50];

int main() {
	cin >> n >> m >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> circle[i][j].val;
			circle[i][j].isDel = false;
		}
	}

	while(t--) {
		int x, d, k;
		cin >> x >> d >> k;

		// 회전 (x의 배수 원판들 모두 회전!)
		for (int i = x - 1; i < n; i += x) {
			int cnt = k;
			while (cnt--) {
				if (d == 0) { // 시계
					int temp = circle[i][m - 1].val;
					for (int j = m - 1; j > 0; j--) {
						circle[i][j].val = circle[i][j - 1].val;
					}
					circle[i][0].val = temp;
				}
				else { // 반시계
					int temp = circle[i][0].val;
					for (int j = 0; j < m - 1; j++) {
						circle[i][j].val = circle[i][j + 1].val;
					}
					circle[i][m - 1].val = temp;
				}
			}
		}

		//isDel 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				circle[i][j].isDel = false;
			}
		}

		bool isThereDel = false;

		// 인접한 수 삭제 여부 체크
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (circle[i][j].val == NULL) 
					continue;

				// 좌우 (원형)
				int next = (j + 1) % m;
				if (circle[i][next].val == circle[i][j].val) {
					circle[i][j].isDel = true;
					circle[i][next].isDel = true;
					isThereDel = true;
				}

				// 위
				if (i > 0 && circle[i - 1][j].val == circle[i][j].val) {
					circle[i][j].isDel = true;
					circle[i - 1][j].isDel = true;
					isThereDel = true;
				}

				// 아래
				if (i < n - 1 && circle[i + 1][j].val == circle[i][j].val) {
					circle[i][j].isDel = true;
					circle[i + 1][j].isDel = true;
					isThereDel = true;
				}
			}
		}

		// 삭제 or 평균 조정
		if (isThereDel) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (circle[i][j].isDel) {
						circle[i][j].val = NULL;
					}
				}
			}
		}

		else {
			double sum = 0;
			int cnt = 0;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (circle[i][j].val != NULL) {
						sum += circle[i][j].val;
						cnt++;
					}
				}
			}

			if (cnt == 0) continue;

			double avg = sum / cnt;

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (circle[i][j].val == NULL) 
						continue;

					if (circle[i][j].val > avg) circle[i][j].val--;
					else if (circle[i][j].val < avg) circle[i][j].val++;
				}
			}
		}
	}

	for (int a = 0; a < n; a++) {
		for (int b = 0; b < m; b++) {
			if (circle[a][b].val != NULL) {
				ans += circle[a][b].val;
			}
		}
	}

	cout << ans;
	return 0;
}