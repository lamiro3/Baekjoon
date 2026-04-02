#include <iostream>

using namespace std;

int main() {
	int n, x;
	int v[250000];
	cin >> n >> x;

	for (int i = 0; i < n; i++)
		cin >> v[i];

	int right = x - 1;
	int sum = 0, ans = 0, cnt = 0;
	for (int left = 0; left <= n - x; left++) {
		if (left == 0) {
			for (int i = 0; i <= right; i++)
				sum += v[i];
		}
		else {
			sum -= v[left - 1];
			sum += v[++right];
		}

		if (ans < sum) {
			ans = sum;
			cnt = 1;
		}

		else if (ans == sum)
			cnt++;
	}

	if (ans == 0)
		cout << "SAD";
	else
		cout << ans << "\n" << cnt;

	return 0;
}