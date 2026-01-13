#include <iostream>
#include <string>

using namespace std;

int main() {
	string ISBN;
	int sum = 0, m;
	int tgtIdx, tgt;
	getline(cin, ISBN);

	for (int i = 0; i < 12; i++) {
		if (ISBN[i] == '*')
			tgtIdx = i;
		else // 가중치 고려하여 합산
			sum += ((ISBN[i] - '0') * (i % 2 == 0 ? 1 : 3))%10;
	}

	m = ISBN[12] - '0'; // 마지막 숫자
	tgt = (20 - (sum % 10) - m) % 10; // 음수 대비해 +10 후 mod 10으로 연산

	if (tgtIdx % 2 == 0)
		cout << tgt;
	else
		if (tgt % 3 == 0)
			cout << tgt / 3;
		else if (tgt % 3 == 1)
			cout << tgt/3 + 7;
		else
			cout << tgt/3 + 4;

	return 0;
}