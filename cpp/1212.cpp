#include <iostream>
#include <algorithm>

using namespace std;

string OctToDec(char c) {
	int n = c - '0';
	string ans = "";

	for (int i = 0; i < 3; i++) {
		ans = char('0' + (n % 2)) + ans;
		n /= 2;
	}

	return ans;
}

int main() {
	string octal, binary;
	cin >> octal;

	for (char c : octal)
		binary += OctToDec(c);

	int i = 0;
	
	while (i < binary.size() && binary[i] == '0')
		i++;

	if (binary.size() == i)
		cout << 0;
	else
		cout << binary.substr(i);

	return 0;
}