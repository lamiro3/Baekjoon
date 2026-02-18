#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> v(N);
	vector<int> ans(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

	for(int i = 0; i < N; i++) {
		int j = 0;

		// 빈 공간은 본인보다 큰 친구 들어가야 하므로 PASS
		while (v[i] > 0) {
			if (ans[j] == 0)
				v[i]--;
			j++;
		}

		// 앞선 과정으로 도착한 곳이 빈 공간이 아니라면 나올 때까지 이동
		while (ans[j] != 0)
			j++;

		// 해당 공간에 답 삽입
		ans[j] = i + 1;
	}

	for (int i = 0; i < N; i++) {
		cout << ans[i];
		if (i < N - 1)
			cout << " ";
	}

	return 0;
}