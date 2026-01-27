#include <iostream>
#include <map>
#include <string>

typedef long long LL;
using namespace std;

int main() {
	LL T;
	cin >> T;

	while (T--) {
		LL k, len = 0;
		cin >> k;

		string cmd;
		LL num;
		map<LL, int> mp;

		while (k--) {

			cin >> cmd >> num;
			
			if (cmd == "I") {
				mp[num]++;
			}

			else if (cmd == "D" && !mp.empty()) {
				if (num == 1) {
					auto max = prev(mp.end());
					if (--(max->second) == 0) // 존재했던 값이라면
						mp.erase(max);
				}
				else {
					auto min = mp.begin();
					if (--(min->second) == 0)
						mp.erase(min);
				}
			}
		}

		if (mp.empty())
			cout << "EMPTY\n";
		else
			cout << prev(mp.end())->first << " " << mp.begin()->first << "\n";
	}
	return 0;
}
