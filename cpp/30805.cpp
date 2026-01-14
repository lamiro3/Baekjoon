#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> A, B, ans;

/* 
<사전 순서 기준 최후위 수열 return>
	1. 맨 앞 숫자가 커야 가장 후위
	2. 겹치는 수들 중 가장 큰 수 탐색
	3. 앞서 찾아낸 수의 A, B 내 위치 기준 뒷 부분 수열에 대해 1,2 과정 반복
*/

void getLastCS(int a, int b) {
	int maxVal = -1;
	int nexta, nextb;

	for (int i = a; i < N; i++) {
		for (int j = b; j < M; j++) {
			if (A[i] == B[j] && maxVal < A[i]) {
				maxVal = A[i];
				nexta = i;
				nextb = j;
			}
		}
	}

	if (maxVal == -1) return; // 겹치는 수가 없었다면 갱신 X
	
	ans.push_back(maxVal);
	getLastCS(nexta + 1, nextb + 1);

	return;
}

int main() {
	// I/O 좀 더 빠르게 하는 친구들
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// input
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A.push_back(a);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		int b;
		cin >> b;
		B.push_back(b);
	}

	// calculate
	getLastCS(0, 0);

	// output
	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x << " ";
	}

	return 0;
}