#include <iostream>
#include <vector>
#include <algorithm>
#define LL long long

using namespace std;

LL N, cnt = 0;
vector<LL> A, B, C, D, AB, CD;

LL LowerBound(LL left, LL right, LL tgt) {
	while (left < right) {
		LL mid = (left + right) / 2;
		if (CD[mid] < tgt)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

LL UpperBound(LL left, LL right, LL tgt) {
	while (left < right) {
		LL mid = (left + right) / 2;
		if (CD[mid] <= tgt)
			left = mid + 1;
		else
			right = mid;
	}
	return left;
}

int main() {
	cin >> N;
	A.resize(N);
	B.resize(N);
	C.resize(N);
	D.resize(N);

	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			AB.push_back(A[i] + B[j]);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			CD.push_back(C[i] + D[j]);

	sort(CD.begin(), CD.end());

	for (LL i = 0; i < AB.size(); i++) {
		LL tgt = -AB[i];
		cnt += (UpperBound(0, CD.size(), tgt) -
			LowerBound(0, CD.size(), tgt));
	}

	cout << cnt;

	return 0;
}