#include <iostream>
#include <cmath>

using namespace std;

/*
최악의 경우 == 강도 가장 센 경우(더 많이 때리게 되므로)

응집수정 파괴하기 전까지 내리치는 횟수 최소화 전략
output: 응집수정 파괴하기까지 내리치는 최대 횟수?

Xk <= F < Xk + W ~ 응집수정 파괴 및 폭발 X 조건
Xk 가 max이어야 하므로
Xk = 0, w, 2w, ... 대입

그러다가 Xk = aw일 때 P가 [aw, (a+1)w)에 속하게 됨
즉, Xk,max = aw;

따라서 답은 a+1 = ceil(P / W)와 같음.
*/

int main() {
	double N, K, P, W, ans;

	cin >> N >> K >> P >> W;

	cout << ceil(P / W);
}