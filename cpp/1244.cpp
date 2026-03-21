#include <iostream>

using namespace std;

int S, N;
int switches[101];

void toggle(int i) {
	switches[i] = (switches[i] + 1) % 2;
}

int main() {
	cin >> S;

	for (int i=1; i<=S; i++)
		cin >> switches[i];

	cin >> N;

	while (N--) {
		int gender, n;
		cin >> gender >> n;

		if (gender == 1) {
			for (int i = n; i <= S; i += n)
				toggle(i);
		}

		else {
			int left = n - 1;
			int right = n + 1;
			toggle(n);

			for (int i = 0; left >= 1 && right <= S; i++) {
				if (switches[left] != switches[right])
					break;
				toggle(left);
				toggle(right);
				left--;
				right++;
			}
		}
	}

	for (int i=1; i<=S; i++) {
		cout << switches[i] << ' ';
		if (i % 20 == 0)
			cout << '\n';
	}

	return 0;
}