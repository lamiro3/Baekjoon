#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long
using namespace std;

int main() {
	int N;
	cin >> N;

	LL prev;
	vector<LL> gaps;

	for (int i = 0; i < N; i++) {
		LL cur;
		cin >> cur;
		if (i > 0) {
			gaps.push_back(cur - prev);
		}
		prev = cur;
	}

	LL GCD = 1;
	LL min_gap = min(*min_element(gaps.begin(), gaps.end()), gaps[0]);

	for (int n = 1; n<=min_gap; n++){
		bool valid = true;
		for (LL gap : gaps) {
			if (gap % n != 0) {
				valid = false;
				break;
			}
		}
		if (valid) {
			GCD = n;
		}
	}

	LL ans = 0;

	for (LL gap : gaps) {
		ans += gap / GCD - 1;
	}

	cout << ans << "\n";
	return 0;
}