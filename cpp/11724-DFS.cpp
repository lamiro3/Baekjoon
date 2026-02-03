#include <iostream>
#include <vector>

using namespace std;

struct Vertex {
	int num;
	vector<Vertex*> next;
};

long N, M;

bool visited[1001] = { false, };
vector<Vertex> V(1001);

// 재귀이므로 DFS
void connect(Vertex& v) {
	visited[v.num] = true;

	for (Vertex* nextv : v.next) {
		if (visited[nextv->num])
			continue;
		connect(*nextv); // 연결된 정점들 중 아직 방문하지 않았다면 방문
	}
}

int main() {
	int ans = 0;
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		V[i].num = i;

	while (M--) {
		int a, b;
		cin >> a >> b;
		// 양방향 그래프
		V[a].next.push_back(&V[b]);
		V[b].next.push_back(&V[a]);
	}

	for (int i = 1; i <= N; i++) {
		if (visited[i])
			continue;
		connect(V[i]); // 아직 연결 안됐다면 연결
		ans++; // union 개수 + 1
	}

	cout << ans;

	return 0;
}