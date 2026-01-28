#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
	ll N, B, C, cnt=0;
	cin >> N;

	vector<ll> A(N);

	for (int i = 0; i < N; i++)
		cin >> A[i];

	cin >> B >> C;

	for (int a : A) {
		a -= B;
		cnt++;
		
		if (a > 0)
			cnt += (a%C == 0) ? a/C : a/C + 1;
	}

	cout << cnt;

	return 0;
}