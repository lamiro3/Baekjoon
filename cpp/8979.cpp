#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <pair<int, long >> countries(n);	

	for (int i = 0; i < n; i++) {
		int country, gold, silver, bronze;
		long point;
		cin >> country >> gold >> silver >> bronze;
		point = gold * 1000000 + silver * 1000 + bronze;
		countries.push_back({ country, point });
	}

	sort(countries.begin(), countries.end(), [](const pair<int, long>& a, const pair<int, long>& b) {
		return a.second > b.second; // 내림차순 정렬
	});
	
	int rank = 1;
	int cnt = -1;
	for (int i = 0; i < n; i++) {
		cnt++;

		if (i > 0 && countries[i].second < countries[i-1].second) {
			rank += cnt;
			cnt = 0;
		}

		if (countries[i].first == k) {
			cout << rank << endl; // 국가 번호가 k인 국가의 순위 출력
			break;
		}
	}
	return 0;
}