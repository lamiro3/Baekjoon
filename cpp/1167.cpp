#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

struct Vertex {
	int to;
	int dis;
};

int maxDis = 0, maxVer = 0; // 지름, Ver 1에서 가장 먼 정점
bool visited[100001] = { false, };
vector<vector<Vertex>> tree(100001, vector<Vertex>(1, {0, 0}));

void DFS(int ver, int dis) {
	if (visited[ver]) // 이미 방문했다면 return
		return;

	if (dis > maxDis) { // 지름 갱신
		maxDis = dis;
		maxVer = ver;
	}

	visited[ver] = true; // 방문 처리

	for (int i = 1; i < tree[ver].size(); i++) { // 맨 처음은 {0,0}이므로 1부터 시작
		int next = tree[ver][i].to;
		int nextDis = tree[ver][i].dis;
		DFS(next, dis + nextDis);
	}
}

int main() {
	int V;
	cin >> V;

	int from, to, dis;

	for (int i = 1; i < V+1; i++) {
		cin >> from;

		while (1) {
			cin >> to;
			if (to == -1) break;
			cin >> dis;
			
			tree[from].push_back({to, dis});
			tree[to].push_back({from, dis});
		}
	}

	DFS(1, 0); // 1에서 가장 먼 정점 찾기
	memset(visited, false, sizeof(visited)); // visited 초기화
	DFS(maxVer, 0); // 가장 먼 정점에서 가장 먼 정점 찾기

	cout << maxDis << "\n";

	return 0; 
}