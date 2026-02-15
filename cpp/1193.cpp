#include <iostream>

using namespace std;

int X;

int main() {
	cin >> X;
	long n = 1;
	long gap = 1;

	while (1) {
		n += gap;
		if (X < n) {
			long ptr = n - gap;
			long big = gap;
			long small = 1;
			bool isEven = big % 2 == 0;

			while (ptr < X) {
				big--;
				small++;
				ptr++;
			}

			if (isEven)
				cout << small << "/" << big;
			else
				cout << big << "/" << small;

			break;
		}
		gap++;
	}

	return 0;
}