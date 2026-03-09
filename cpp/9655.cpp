#include <iostream>

using namespace std;

int N;
bool dp[1001];

int main() {
	cin >> N;
	dp[1] = true;
	dp[2] = false;
	dp[3] = true;

	for (int i = 4; i <= N; i++) {
		if (!dp[i - 1] || !dp[i - 3]) {
			dp[i] = true;
		}
		else {
			dp[i] = false;
		}
	}

	if (dp[N])
		cout << "SK";
	else
		cout << "CY";

	return 0;
}