#include <iostream>
#include <vector>

using namespace std;

int N;

int main() {
	cin >> N;

	vector<int>T(N + 1);
	vector<int>P(N + 1);
	vector<int>dp(N + 2, 0);
	// dp[i] = i 번째 날 시작 전까지의 최대 수익
	for (int i = 1; i <= N; i++)
		cin >> T[i] >> P[i];

	int i = 1;

	while (i <= N) {
		// 전 날 상담 안하고 넘어갈 경우
		dp[i+1] = max(dp[i], dp[i + 1]);

		// 상담하게되는 경우
		if (i + T[i] - 1 <= N) { // 상담일이 당일 날 포함이므로
			dp[i + T[i]] = max(dp[i + T[i]], dp[i] + P[i]);
		}
		i++;
	}

	cout << dp[N+1];
	return 0;
}