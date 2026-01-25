#include <iostream>
#include <vector>
#include <string>

#define MINUS '-'
#define PLUS '+'

using namespace std;

bool isOper(char c) {
	if (c == MINUS || c == PLUS)
		return true;
	return false;
}

int main() {
	string exp;
	getline(cin, exp);

	bool metMinus = false;
	char prevOper = PLUS;
	int ptr = 0;
	int ans = 0;
	int brac = 0;

	for (int i = 0; i < exp.size(); i++) {
		// i번째 글자가 연산자
		if (isOper(exp[i])) {
			prevOper = exp[i];

			// - 를 만난 적이 없다면
			if (!metMinus) {
				ans += stoi(exp.substr(ptr, i - ptr));
				ptr = i + 1;
				
				if (exp[i] == MINUS)
					metMinus = true;
			}

			// - 를 만난 적이 있다면
			else {
				// 괄호 부분합에 이전 숫자 더해
				brac += stoi(exp.substr(ptr, i - ptr));
				ptr = i + 1;

				// 이번 연산자가 - 라면
				if (exp[i] == MINUS) {
					// ans에 괄호 부분합을 빼
					ans -= brac;
					// 괄호 부분합 reset
					brac = 0;
				}
			}
		}

		// 마지막일때
		else if (i == (exp.size() - 1)) {
			// 마지막 숫자
			int last = stoi(exp.substr(ptr, i + 1 - ptr));

			// -를 만난 적이 있다면
			if (metMinus) {
				// 이전 연산자가 + -> 아직 괄호가 안닫혔다는 뜻
				if (prevOper == PLUS) {
					// 부분합에 숫자를 더해, ans에 부분합을 빼
					brac += last;
					ans -= brac;
					brac = 0;
				}

				// 이전 연산자가 - -> 괄호가 닫힌 후
				else
					// ans에 last 값을 빼
					ans -= last;
			}

			// - 를 만난 적이 없다면
			else
				// ans에 last 값 더해
				ans += last;
		}
	}

	std::cout << ans;

	return 0;
}