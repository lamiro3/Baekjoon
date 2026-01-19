#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N, sum;
	cin >> N;
	sum = N * (N + 1) / 2;

	// 합이 홀수라면
	if (sum % 2) {
		cout << 0;
		return 0;
	}

	sum /= 2;
	vector<long long> dp(sum + 1, 0);
	dp[0] = 1;

	for (int i = 1; i <= N; i++) {
		for (int j = sum; j >= i; j--) {
			dp[j] += dp[j - i];
		}
	}

	cout << dp[sum]/2;
	return 0;
}