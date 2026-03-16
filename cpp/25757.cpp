#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

map<char, int> game = {
	{'Y', 2},
	{'F', 3},
	{'O', 4}
};

vector<string> users;

int main() {
	int N;
	char G;

	cin >> N >> G;

	while (N--) {
		string username;
		cin >> username;
		users.push_back(username);
	}

	// 중복 제거
	set<string> real_users(users.begin(), users.end());
	
	cout << real_users.size() / (game[G] - 1);
	return 0;
}