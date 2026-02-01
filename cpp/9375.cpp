#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		// 의상 종류당 해당 의상 개수 maping
		map<string, int> clothes;

		while (n--) {
			string a, b;
			cin >> a >> b;
			
			if (clothes.find(b) != clothes.end())
				clothes.insert({ b, 0 });
			clothes[b]++;
		}

		int ans = 1;

		/*
		의상 종류가 k개 ~ 각 종류에 ni개의 의상이 있을 때
		ans = (n1 + 1)(n2 + 1)(n3 + 1) ... (nk + 1) - 1
		*/
		for (auto [key, val] : clothes) {
			ans *= (val + 1);
		}

		ans--;
		
		cout << ans << endl;
	}
	return 0;
}