#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c;
	while (1) {
		cin >> a >> b >> c;

		if (a == b && b == c && c == a && a == 0)
			return 0;

		int L = max({ a, b, c });

		if ((L == a && L < b + c) ||
			(L == b && L < a + c) ||
			(L == c && L < a + b)) {

			if (a == b && b == c && c == a)
				cout << "Equilateral" << "\n";

			else if ((a == b && b != c) ||
				(b == c && c != a) ||
				(c == a && a != b))
				cout << "Isosceles" << "\n";
			else
				cout << "Scalene" << "\n";
		}

		else
			cout << "Invalid" << "\n";
	}

	return 0;
}