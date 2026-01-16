#include <iostream>
#include <vector>
#include <algorithm>

#define edge pair<pair <int, int>, int>
using namespace std;

int V, E, ans = 0;
int parent[10001];
vector<edge> edges;

// 최상단 부모 vertex
int findBoss(int v) {
	if (parent[v] == v) return v;
	return parent[v] = findBoss(parent[v]);
}

// 같은 그룹으로 묶어버리기
void Tie(int v1, int v2) {
	int p1 = findBoss(v1);
	int p2 = findBoss(v2);
	
	if (p1 != p2) parent[p2] = p1;
}

// 최소 스패닝 트리 ~ 크루스칼 알고리즘 이용
void kruskal() {
	int cnt = 0;
	
	for (int i = 0; i < edges.size(); i++) {
		if (cnt == V - 1) break; // 최소 간선 수 도달 시 종료

		edge now = edges[i];

		// edge 두 정점
		int v1 = now.first.first;
		int v2 = now.first.second;

		// 사이클 발생 시 pass
		if (findBoss(v1) == findBoss(v2)) continue;
		
		ans += now.second; // 선택한 간선 가중치 합산
		Tie(v1, v2); // 간선 연결
		cnt++; // 간선 수 갱신
	}
}

int main() {
	cin >> V >> E;
	
	for (int i = 0; i < E; i++) {
		int start, end, weight;
		cin >> start >> end >> weight;
		edges.push_back({ {start, end}, weight });
	}

	// 연결되지 않은 상태이므로 각 vertex의 부모를 자신으로 set
	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	// 가중치 기준 edges 오름차순 정렬
	sort(edges.begin(), edges.end(),
		[](edge& a, edge& b) {
			return a.second < b.second;
		});

	kruskal();
	cout << ans;

	return 0;
}