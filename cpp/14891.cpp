#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

string gears[5];

void turn(string & gear, int dir) {
	if (dir == -1) { // 반시계방향
		string temp = gear.substr(1, 7);
		gear = temp + gear[0];
	}

	else { // 시계방향
		string temp = gear.substr(0, 7);
		gear = gear[7] + temp;
	}
}

int main() {
	for (int i = 1; i <= 4; i++) {
		cin >> gears[i];
	}

	int k, ans = 0;
	cin >> k;

	while (k--) {
		int n, dir;
		cin >> n >> dir;

		int L = n - 1, R = n + 1, now = n, now_dir = dir;
		int dirs[5] = { 0, }; // 기어들의 회전 여부 및 방향 저장
		
		dirs[n] = dir;

		while (L >= 1) {
			// 현재 기어 9시 != 왼쪽 기어 3시 ~ 왼쪽 기어 반대 방향으로 회전
			if (gears[now][6] != gears[L][2]) { 
				now_dir *= -1;
				dirs[L] = now_dir;
				now = L;
				L--;
			}
			// 만약 맞닿은 극이 같다면 그 뒤는 회전하지 않으므로 break
			else
				break;
		}

		now = n, now_dir = dir;

		while (R <= 4) {
			// 현재 기어 3시 != 오른쪽 기어 9시 ~ 오른쪽 기어 반대 방향으로 회전
			if (gears[now][2] != gears[R][6]) {
				now_dir *= -1;
				dirs[R] = now_dir;
				now = R;
				R++;
			}
			// 이하 동일
			else
				break;
		}

		// 각 기어들의 회전 가능 여부 및 방향 파악 후 회전 진행
		for (int i = 1; i <= 4; i++) {
			if (dirs[i] != 0)
				turn(gears[i], dirs[i]);
		}
	}

	for (int i = 1; i <= 4; i++) {
		char twelve = gears[i][0];

		if (twelve == '1')
			ans += pow(2, i - 1);
	}

	cout << ans;

	return 0;
}