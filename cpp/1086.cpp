#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#define LL long long
using namespace std;

int N, K;
vector<string> nums(15);

// getAns 연산에 필요한 데이터 전처리
vector<LL> lengths(15), modK(15), pow10modK(50);
vector<vector<LL>> dp(1 << 15, vector<LL>(101, -1));

void getpow10modK() {
	pow10modK[0] = 1;
	for (int i = 1; i < 50; i++) {
		pow10modK[i] = pow10modK[i - 1] * 10 % K;
	}
}

LL getAns(int flag, LL v) {
	// 순열 케이스가 완성됐다면 (모든 숫자가 선택됐다면)
	if (flag + 1 == (1 << N))
		// 해당 케이스의 값이 K로 나눠 떨어지면 1, 아니면 0을 반환
		return v == 0;

	LL& ret = dp[flag][v];

	// 갱신된 적이 있다면 해당 값을 반환
	if (ret != -1)
		return ret;

	// 그렇지 않다면 0으로 초기화한 뒤 다음 케이스들을 탐색
	ret = 0;

	for (int i = 0; i < N; i++) {
		if (flag & (1 << i))
			continue;
		ret += getAns(flag | (1 << i), (v * pow10modK[lengths[i]] + modK[i]) % K);
	}

	// 해당 root case 값 = 자식 case 값들의 합을 반환
	return ret;
}

int main() {
	LL facN = 1; // 전체 경우의 수: nPn = n!
	std::cin >> N;

	for(int i=0; i<N; i++) {
		string num;
		std::cin >> num;
		nums[i] = num;
		lengths[i] = num.size();
		facN *= (i + 1);
	}

	std::cin >> K;

	for (int i = 0; i < N; i++) {
		string num = nums[i];
		int temp = 0;

		for (char n : num) {
			temp *= 10;
			temp += (n - '0');
			temp %= K;
		}
		modK[i] = temp;
	}

	getpow10modK();

	LL son = getAns(0, 0);
	LL GCD = gcd(son, facN);

	if (son == 0)
		cout << 0 << "/" << 1 << "\n";
	else
		cout << son / GCD << "/" << facN / GCD << "\n";
	
	return 0;
}