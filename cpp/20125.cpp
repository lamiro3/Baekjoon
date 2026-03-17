#include <iostream>
#include <string>
#define BODY '*'
#define EMPTY '_'

using namespace std;

int di[4] = { -1, 0, 1, 0 };
int dj[4] = { 0, 1, 0, -1 };

int main() {
	int n, hi, hj, wi, wj;
	bool isDone = false;
	cin >> n;

	string s[1000];

	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n && !isDone; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == BODY) {
				bool isHeart = true;

				for (int k = 0; k < 4; k++) {
					hi = i + di[k];
					hj = j + dj[k];
					if (hi < 0 || hi >= n || hj < 0 || hj >= n || s[hi][hj] != BODY) {
						isHeart = false;
						break;
					}
				}

				if (isHeart) {
					hi = i;
					hj = j;
					isDone = true;
					break;
				}
			}
		}
	}

	int arm_l = 0, arm_r = 0, leg_l = 0, leg_r = 0, waist = 0;
	int i = hi, j = hj - 1;

	while (s[i][j] == BODY) {
		arm_l++;
		j--;
		if (j < 0)
			break;
	}

	i = hi, j = hj + 1;
	while (s[i][j] == BODY) {
		arm_r++;
		j++;
		if (j >= n)
			break;
	}

	i = hi, j = hj;
	while (s[++i][j] == BODY && i < n)
		waist++;

	wi = i - 1, wj = j;

	i = wi + 1, j = wj - 1;
	while (s[i][j] == BODY) {
		leg_l++;
		i++;
		if (i >= n)
			break;
	}
		

	i = wi + 1, j = wj + 1;
	while (s[i][j] == BODY) {
		leg_r++;
		i++;
		if (i >= n)
			break;
	}
		

	cout << hi + 1 << ' ' << hj + 1 << '\n';
	cout << arm_l << ' ' << arm_r << ' ' << waist << ' ' << leg_l << ' ' << leg_r << '\n';

	return 0;
}