#include <iostream>

using namespace std;

long dp[91];

long ans(int n) {
	if (dp[n] != -1)
		return dp[n];
	dp[n] = ans(n - 1) + ans(n - 2);
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i <= 90; i++)
		dp[i] = -1;

	dp[0] = 0;
	dp[1] = 1;

	cout << ans(n);
}