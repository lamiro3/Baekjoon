#include <iostream>
#include <vector>
using namespace std;

long N, K;
vector<long> tree;

void initSegTree(long node, long start, long end) {
	if (start == end)
		tree[node] = 1;

	else {
		long mid = (start + end) / 2;
		initSegTree(node * 2, start, mid);
		initSegTree(node * 2 + 1, mid + 1, end);

		// 왼쪽 구간 생존자 수 + 오른쪽 구간 생존자 수 누적합
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

// n번째 생존자 찾기
long find(long node, long start, long end, long n) {
	if (start == end)
		return start;
	else {
		long mid = (start + end) / 2;
		if (tree[node * 2] >= n)
			return find(node * 2, start, mid, n);
		else
			return find(node * 2 + 1, mid + 1, end, n - tree[node * 2]);
	}
}

// 해당 위치의 노드(즉, 해당 생존자) 제거 및 트리 갱신
void update(long node, long start, long end, long pos) {
	if (start == end)
		tree[node] = 0;

	else {
		long mid = (start + end) / 2;
		if (pos <= mid)
			update(node * 2, start, mid, pos);
		else
			update(node * 2 + 1, mid + 1, end, pos);

		// 왼쪽 구간 생존자 수 + 오른쪽 구간 생존자 수 누적합
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}
}

int main() {
	cin >> N >> K;

	// 완전 이진트리 꼴이기 때문에 
	tree.resize(4 * N);
	initSegTree(1, 1, N);

	vector<long> ans;
	long pos = 0;

	for (int i = 0; i < N; i++) {
		// 현재 생존자 수
		long aliveCnt = tree[1];

		// 다음 위치 갱신
		pos = (pos + K - 1) % aliveCnt;

		// 다음 위치에 들어갈 값 탐색
		long tgt = find(1, 1, N, pos+1);

		ans.push_back(tgt);
		update(1, 1, N, tgt);
	}

	if (N == 1) {
		cout << "<" << 1 << ">";
		return 0;
	}

	for (int i = 0; i < N; i++) {
		if (i == 0)
			cout << "<" << ans[i] << ", ";

		else if (i == N - 1)
			cout << ans[i] << ">";

		else
			cout << ans[i] << ", ";
	}
	return 0;
}