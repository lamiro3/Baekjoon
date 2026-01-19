#include <iostream>
#include <vector>
typedef long long LL;
using namespace std;

// duals = (b,b, ..) 꼴 개수
LL N, ans = 0, duals = 0;

vector<LL> numbers;
vector<LL> cntL, cntR; // 정방 count, 역방 count

int main() {
	cin >> N;
	numbers.resize(N);
	cntL.assign(N, 0);
	cntR.assign(N, 0);

	for (int i = 0; i < N; i++) {
		LL num;
		cin >> num;
		numbers[i] = num;
		cntL[num]++;
	}

	for (int i = N - 1; i > -1; i--) {
		LL b = numbers[i];
		cntL[b]--;
	
		// (a, b1, b2, ...)꼴에서 가장 왼쪽에 있는 b1일 경우
		if (cntL[b] == 0)
			ans += duals;

		cntR[b]++;
		if (cntR[b] == 2)
			duals += 1;

		else if (cntR[b] == 3)
			ans -= 1;
	}

	cout << ans;
	return 0;
}