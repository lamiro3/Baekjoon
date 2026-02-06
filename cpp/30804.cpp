#include <iostream>
#include <vector>
#include <cmath>
#define LL long long

using namespace std;

LL N, ans = 0;
// i번 과일의 개수
vector<LL> arr(10, 0);

int main() {
	cin >> N;
	vector<int> fruit(N);

	for (LL i = 0; i < N; i++)
		cin >> fruit[i];

	int kind = 0;
	LL left = 0;

	// 모든 경우의 수 ~ BruteForce & two pointer
	for (LL right = 0; right < N; right++) {
		if (arr[fruit[right]] == 0)
			kind++;
		arr[fruit[right]]++;

		// 종류가 3개 이상일때 left 포인터 이동
		while (kind > 2) {
			arr[fruit[left]]--;
			if (arr[fruit[left]] == 0) kind--;
			left++;
		}

		// 최댓값 갱신
		ans = max(ans, right - left + 1);
	}

	cout << ans;

	return 0;
}