#include <iostream>
using namespace std;

int main() {
	int p;
	cin >> p;

	while (p--) {
		int t, ans = 0;
		int arr[20];

		cin >> t;

		for (int i = 0; i < 20; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < 20; i++) {
			for (int j = 0; j <= i - 1; j++) {
				if (arr[i] < arr[j])
					ans++;
			}
		}

		cout << t << " " << ans << endl;
	}
	return 0;
}