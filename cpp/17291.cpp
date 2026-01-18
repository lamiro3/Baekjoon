#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> dp;

// dp[n] = n년 말 존재하는 벌레의 수
// 점화식 유도 (n >= 4)
// 1) dp[n] = dp[n-1] + dp[n-2] + dp[n-3] <* n이 짝수>
// 2) dp[n] = 2 * dp[n-1] <* n이 홀수>

int cal(int n) {
	if (n < 4)
		return dp[n];

	if (n % 2 == 0)
		dp[n] = cal(n - 1) + cal(n - 2) + cal(n - 3);
	else
		dp[n] = 2 * cal(n - 1);

	return dp[n];
}

int main() {
	cin >> N;
	dp.resize(N + 1, 0);
	
	if (N < 4) {
		if (N == 1)
			cout << 1;
		else if (N == 2)
			cout << 2;
		else
			cout << 4;
	}

	else {
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		
		cout << cal(N);
	}
	return 0;
}