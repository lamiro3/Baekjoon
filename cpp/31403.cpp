#include <iostream>
#include <string>
using namespace std;
string A, B, C;

int main() {
	cin >> A;
	cin >> B;
	cin >> C;
	cout << stoi(A) + stoi(B) - stoi(C) << "\n";
	cout << stoi(A + B) - stoi(C) << "\n";
	return 0;
}