#include <iostream>
#define MAX 100000
using namespace std;

long N;
int dp[MAX+1];

int main() {
	cin >> N;

	dp[0] = 0;

	for (int i = 1; i <= N; i++) {
		dp[i] = i; // 최악: 1로만 더했을 때
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	}

	cout << dp[N];
	return 0;
}