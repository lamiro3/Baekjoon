#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#define LL long long
using namespace std;

string N;
int K;
LL ans = -1;

// idx: 결정할 자리 수(위치)
// mask: 현재까지 사용된 숫자들의 bitmask
// isGreater: 이미 N보다 큰 수가 확정되었는가?
// s: 현재까지 만들어진 숫자
void getAns(int idx, int mask, bool isGreater, string s) {
	// 답 찾았다면 종료
	if (ans != -1)
		return;

	int usedCnt = __builtin_popcount(mask);

	// 자릿수 모두 채웠을 시
	if (idx == s.size()) {
		if (usedCnt == K)
			ans = stoll(s);
		return;
	}

	// 남은 자리 수(위치)로 K개 채울 수 없는 경우
	int remain = s.size() - idx;
	if (usedCnt + remain < K)
		return;

	// 현재 자리 수(위치)에 가능한 숫자 범위 시작점
	int start = isGreater ? 0 : N[idx] - '0';

	for (int n = start; n < 10; n++) {
		int nextmask = mask | (1 << n);
		int nextUsedCnt = __builtin_popcount(nextmask);

		// 숫자 종류 K개 초과 시 패스
		if (nextUsedCnt > K)
			continue;

		bool nextIsGreater = isGreater || (n > (N[idx] - '0'));

		s[idx] = n + '0';
		getAns(idx + 1, nextmask, nextIsGreater, s);
	}
}

int main() {
	cin >> N >> K;

	// N과 같은 자리수에서 탐색
	string temp = N;
	getAns(0, 0, false, temp);

	// 만약 전 과정에서 답이 안나왔다면, 자리 늘려가며 탐색
	int curLen = N.size();
	while (ans == -1) {
		curLen++;
		string next_n(curLen, '0');
		string start = "";
		for (int i = 0; i < curLen; i++)
			start += '0';

		// 자리 늘렸으므로 첫 자리 n & n masking -> 그런 뒤 탐색
		for (int n = 1; n < 10; n++) {
			string s = start;
			s[0] = n + '0';
			getAns(1, 1 << n, true, s);
			if (ans != -1)
				break;
		}
	}

	cout << ans << endl;
	return 0;
}