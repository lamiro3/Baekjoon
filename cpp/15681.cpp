#include <iostream>
#include <vector>

using namespace std;

int N, R, Q;
int dp[100001]; // dp[v] v가 subtree의 root일때 query 값
vector<vector<int>> vertices(100001); // vertices[v]: v vertex의 child
bool visited[100001] = { false, };

void DFS(int v) {
	if (visited[v]) return;

	dp[v] = 1;

	visited[v] = true;

	for (int child : vertices[v]) {
		if (!visited[child]) {
			DFS(child);
			dp[v] += dp[child];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> R >> Q;

	// 간선 정보 입력
	int a, b, q;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		// 무방향 graph이므로 양방으로 묶기
		vertices[a].push_back(b);
		vertices[b].push_back(a);
	}

	DFS(R); // 모든 vertex에 대해 query값 계산
	 
	for (int i = 0; i < Q; i++) {
		cin >> q;
		cout << dp[q] << "\n";
	}

	return  0;
}