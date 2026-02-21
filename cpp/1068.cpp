#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
int del;

int cntLeaf(int cur) {
	if (cur == del)
		return 0;

	if (tree[cur].empty())
		return 1;

	int cnt = 0; // 예하 자식 트리의 리프 노드 개수
	int aftcnt = 0; // 삭제 반영 한 뒤의 자식 개수

	for (int child : tree[cur]) {
		if (child == del)
			continue;
		cnt += cntLeaf(child);
		aftcnt++;
	}

	if (aftcnt == 0)
		return 1;

	return cnt;
}

int main() {
	int N, root = -1;
	cin >> N;

	tree.resize(N);

	for (int i = 0; i < N; i++) {
		int parent;
		cin >> parent;

		if (parent == -1)
			root = i;
		else
			tree[parent].push_back(i);
	}

	cin >> del;

	if (del == root)
		cout << 0;
	else {
		cout << cntLeaf(root);
	}

	return 0;
}