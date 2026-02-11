#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

#define LL long long

using namespace std;

int N;
LL M = LLONG_MIN, m = LLONG_MAX;

vector<int> A;
vector<int> oper;

// 백트래킹 이용 ~ DFS 기반
void getAns(int ptr, LL ans, int plus, int minus, int mul, int div) {
	if (ptr == N) {
		M = max(M, ans);
		m = min(m, ans);
		return;
	}

	if (plus > 0)
		getAns(ptr + 1, ans + A[ptr + 1], plus-1, minus, mul, div);
	if (minus > 0)
		getAns(ptr + 1, ans - A[ptr + 1], plus, minus-1, mul, div);
	if (mul > 0)
		getAns(ptr + 1, ans * A[ptr + 1], plus, minus, mul-1, div);
	if (div > 0)
		getAns(ptr + 1, ans / A[ptr + 1], plus, minus, mul, div-1);
}

int main() {
	cin >> N;

	A.assign(N + 1, 0);
	oper.assign(5, 0);

	for (int i = 1; i <= N; i++)
		cin >> A[i];

	for (int i = 1; i <= 4; i++)
		cin >> oper[i];

	getAns(1, A[1], oper[1], oper[2], oper[3], oper[4]);

	cout << M << endl << m;
	return 0;
}