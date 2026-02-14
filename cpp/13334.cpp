#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define LL long long

using namespace std;

// 특정 시점 ~ MAX: 우선순위 큐 -> O(nlogn)

LL n, d;
vector<pair<LL, LL>> info;

int main() {
	cin >> n;
	info.resize(n);

	for (LL i = 0; i < n; i++) {
		LL h, o;
		cin >> h >> o;

		if (h < o) {
			info[i].first = h;
			info[i].second = o;
		}

		else {
			info[i].first = o;
			info[i].second = h;
		}
	}
	
	cin >> d;
	LL ans = 0;

	// R 기준으로 오름차순 정렬 (R이 같다면 L기준으로)
	sort(info.begin(), info.end(), [](auto L, auto R)->bool {
		if (L.second == R.second)
			return L.first < R.first;
		return L.second < R.second;
	});

	// 최소 힙 ~ 우선순위 큐
	priority_queue<LL, vector<LL>, greater<>> pq;

	for (auto [left, right] : info) {
		// 길이가 d보다 긴 친구들은 제외(어차피 불가능하므로)
		if (right - left > d)
			continue;

		pq.push(left);
		
		// 현재까지 탐색한 직선들 중 left가 가장 작은 것 부터 
		// 길이 d인 직선에 포함되지 않는 직선들은 제외

		while (!pq.empty() && pq.top() < right - d) {
			pq.pop();
		}

		ans = max<LL>(ans, pq.size());
	}

	cout << ans;

	return 0;
}