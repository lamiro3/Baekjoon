#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
typedef struct {
	int cost;
	int cli;
} City;

int C, N;
vector<int> dp(100001, 0);
vector<City> Cities;

/*
1. dp[cost] = 해당 cost로 늘릴 수 있는 잠재 고객 수(cli)의 MAX
2. dp[0] = 0
3. dp[cost] = dp[cost] 현재 값,
			= dp[cost - nth 도시 cost] + nth 도시 cost 당 cli
*/

int main() {
	cin >> C >> N;
	Cities.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> Cities[i].cost >> Cities[i].cli;
	}

	for (int i = 1; i < dp.size(); i++) {
		for (City city : Cities) {
			if (i >= city.cost)
				dp[i] = max(dp[i], dp[i - city.cost] + city.cli);
		}
		
		// 딱 C명이 아닌 적어도 C명 이상이므로...
		if (dp[i] >= C) {
			cout << i << "\n";
			return 0;
		}
	}
}