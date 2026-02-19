#include <iostream>
#include <string>

using namespace std;

string s;
int cnt[2] = { 0, 0 };

int main() {
	cin >> s;
	for (long i = 1; i < s.size(); i++) {
		if (s[i - 1] != s[i]) {
			cnt[s[i - 1]-'0']++;
		}

		if (i == s.size() - 1) {
			cnt[s[i] - '0']++;
		}
	}

	cout << min(cnt[0], cnt[1]);
	return 0;
}