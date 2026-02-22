#include <iostream>

using namespace std;

int main() {
	int x, y;
	cin >> x >> y;

	bool xPos = x > 0;
	bool yPos = y > 0;

	if (xPos && yPos)
		cout << 1;

	else if (!xPos && yPos)
		cout << 2;

	else if (!xPos && !yPos)
		cout << 3;

	else
		cout << 4;
}