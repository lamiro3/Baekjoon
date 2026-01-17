#include <iostream>
#include <cmath>

using namespace std;

int main() {
	long kx1, ky1, kx2, ky2;
	long ox1, oy1, ox2, oy2;

	// 시점 간 거리, 종점 간 거리
	double dis1, dis2;

	/*
	<case>
	(1) 교차, (2) 분리 , (3) 시점/종점 동일, (4) 일치
	=> 어차피 둘 모두 선형 이동 & 등속 이동이기 때문에,
	최대 거리는 시점 간 거리 or 종점 간 거리 중 큰 값
	*/

	cin >> kx1 >> ky1 >> ox1 >> oy1;
	cin >> kx2 >> ky2 >> ox2 >> oy2;

	dis1 = sqrt(pow((kx1 - ox1), 2) + pow((ky1 - oy1), 2));
	dis2 = sqrt(pow((kx2 - ox2), 2) + pow((ky2 - oy2), 2));

	cout.precision(11);
	cout << max(dis1, dis2);

	return 0;
}