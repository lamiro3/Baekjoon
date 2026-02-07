#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N, M, ans = 0;
string P;

int main() {
	cin >> N;
	cin >> M;
	cin >> P;

	for (int i = 0; i < M;) {
		if (P[i] == 'I' && P[i + 1] == 'O' && P[i + 2] == 'I') {
			int cnt = 0;
			int j = i;

			while (j + 2 < M && P[j] == 'I' && P[j + 1] == 'O' && P[j + 2] == 'I') {
				cnt++;
				j += 2;
			}

			if (cnt >= N)
				ans += cnt - N + 1;

			i = j;
		}
		else
			i++;
	}

	cout << ans;
	return 0;
}