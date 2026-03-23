#include <iostream>
#include <stack>

using namespace std;

int ans[500000];

int main() {
	int n, h;
	cin >> n;
	cin >> h;
	ans[0] = 0;

	stack<pair<int, int>> s;
	s.push({ 1, h });

	for (int i = 1; i < n; i++) {
		cin >> h;

		if (h > s.top().second) {
			while (!s.empty() && h > s.top().second)
				s.pop();

			if (s.empty())
				ans[i] = 0;

			else {
				ans[i] = s.top().first;
				if (s.top().second == h)
					s.pop();
			}
		}

		else
			ans[i] = s.top().first;

		s.push({ i + 1, h });
	}

	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';

	return 0;
}