#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	vector<int> q;
	int left = 0, right = 0;
	string output;

	while (n--) {
		string cmd;
		cin >> cmd;

		if (cmd == "push") {
			int a;
			cin >> a;
			q.push_back(a);
			right++;
		}

		else if (cmd == "pop") {
			if (right == left)
				output += "-1\n";
			else {
				output += to_string(q[left]) + "\n";
				left++;
			}
		}

		else if (cmd == "size")
			output += to_string(right - left) + "\n";

		else if (cmd == "empty")
			output += (right == left ? "1\n" : "0\n");

		else if (cmd == "front") {
			if (right == left)
				output += "-1\n";
			else
				output += to_string(q[left]) + "\n";
		}

		else if (cmd == "back") {
			if (right == left)
				output += "-1\n";
			else
				output += to_string(q[right - 1]) + "\n";
		}
	}

	cout << output;

	return 0;
}