#include <iostream>
#include <unordered_map>

using namespace std;

long long N, M;
unordered_map<string, string> v;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		v.insert(make_pair(a, b));
	}

	while (M--) {
		string s;
		cin >> s;
		cout << v.find(s)->second << "\n";
	}

	return 0;
}