#include <iostream>
#include <cstdlib>
#include <string>

typedef long long LL;
using namespace std;

int T;

// 최대공약수 구하기
LL GCD(LL a, LL b) {
	if (b == 0) return a;
	return GCD(b, a%b);
}

// 10^x
LL pow10(int x) {
	LL ans = 1;
	for (int i = 0; i < x; i++)
		ans *= 10;
	return ans;
}

int main() {
	cin >> T;

	for (int i = 0; i < T; i++) {
		string input;
		cin >> input;
		int len = input.length();
		int notLoopCnt = 0;
		int left = -1;
		
		for (int j = 2; j < len; j++) {
			if (input[j] == '(') {
				left = j;
				break;
			}
			notLoopCnt++;
		}

		// 순환소수가 아니라면 left = -1
		if (left == -1) {
			LL mom = pow10(notLoopCnt);
			LL son = stoll(input.substr(2, notLoopCnt));
			LL gcd = GCD(mom, son);

			cout << son / gcd << "/" << mom / gcd << "\n";
		}

		// 순환소수가 맞다면
		else {
			int right = len - 1;
			string notLoop = input.substr(2, notLoopCnt);
			string whole = notLoop;
			whole.append(input.substr(left + 1, right - left - 1));

			/* 비순환 part가 없을 때는 notLoop = ""이기 때문에
			stoll(notLoop) 오류 발생하므로 예외처리 */
			LL base = (notLoopCnt == 0 ? 0 : stoll(notLoop));
			LL mom = pow10(right-left-1+notLoopCnt) - pow10(notLoopCnt);
			LL son = stoll(whole) - base;
			LL gcd = GCD(mom, son);

			cout << son / gcd << "/" << mom / gcd << "\n";
		}
	}

	return 0;
}