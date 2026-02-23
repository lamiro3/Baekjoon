#include <iostream>
#include <algorithm>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	long N;
	long long ans = 0;
	cin >> N;

	vector<long long> v(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	// 거듭제곱은 전처리로(이때도 MOD 처리)
	vector<long long> pow2(N);
	pow2[0] = 1;
	for (int i = 1; i < N; i++)
		pow2[i] = (pow2[i - 1] * 2) % MOD;

	for (int i = 0; i < N; i++) {
		// MOD를 더하는 이유는 음수 방지용
		// 2^i : ith 최대가 되는 경우의 수
		// 2^N-i-1 : ith 최소가 되는 경우의 수
		int w = (pow2[i] - pow2[N - i - 1] + MOD) % MOD;
		ans = (ans + v[i] * w) % MOD;
	}

	cout << ans % MOD;

	return 0;
}