#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long N, M;
vector<int> P;

int FIND(int x) {
	if (P[x] == x)
		return x;
	else
		return P[x] = FIND(P[x]); // 경로 압축
}

void UNION(int x, int y) {
	x = FIND(x);
	y = FIND(y);

	if (x!=y) P[y] = x;
}

int main() {
	int ans = 0;

	cin >> N >> M;
	P.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
		P[i] = i;

	while (M--) {
		int a, b;
		cin >> a >> b;
		UNION(a, b);
	}

	for (int i = 1; i <= N; i++) {
		if (FIND(i) == i) // Union 개수 = root 노드 개수
			ans++;
	}

	cout << ans;

	return 0;
}