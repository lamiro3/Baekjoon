#include <iostream>
#include <vector>
#define MOD 10007
using namespace std;

int C[53][53];

void getComb() {
	for (int i = 0; i <= 52; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
		}
	}
}

int main() {
	int n;
	long long ans = 0;
	cin >> n;

	if (n < 4) {
		cout << 0;
		return 0;
	}

	getComb();

	for (int i = 1; i <= n / 4 && i <= 13; i++) {
		int temp = (C[13][i] * C[52 - 4 * i][n - 4 * i]) % MOD;

		if (i % 2 == 1)
			ans += temp;
		else
			ans = (ans - temp + MOD) % MOD;
	}

	cout << ans % MOD;

	return 0;
}