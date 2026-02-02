#include <iostream>

#define MAX 5
using namespace std;

long N;
int dp[50001];

int main() {
	cin >> N;
	dp[0] = 0;
	dp[1] = 1;

	// [점화식]
	// dp[n] = dp[n-k*k] + 1;
	// ! k*k : n 이하 제곱수 중 MAX

	for (int i = 2; i <= N; i++) {
		int temp = MAX;
		for (int j = 1; j * j <= i; j++)
			temp = min(temp, dp[i - j * j]);

		dp[i] = temp + 1;
	}
		
	cout << dp[N];

	return 0;
}