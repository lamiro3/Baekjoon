#include <iostream>
#include <vector>

using namespace std;

int M;
int S[21] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		string cmd;
		cin >> cmd;

		if (cmd == "add") {
			int x;
			cin >> x;
			S[x] = 1;
		}

		else if (cmd == "remove") {
			int x;
			cin >> x;
			S[x] = 0;
		}

		else if (cmd == "check") {
			int x;
			cin >> x;

			if (S[x])
				cout << 1 << "\n";
			else
				cout << 0 << "\n";
		}

		else if (cmd == "toggle") {
			int x;
			cin >> x;

			if (S[x]) S[x] = 0;
			else S[x] = 1;
		}

		else if (cmd == "all") {
			for (int j = 1; j <= 20; j++)
				S[j] = 1;
		}

		else if (cmd == "empty") {
			for (int j = 1; j <= 20; j++)
				S[j] = 0;
		}
	}

	return 0;
}