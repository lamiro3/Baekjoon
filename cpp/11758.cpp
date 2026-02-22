#include <iostream>
#include <cmath>
#define vec pair<int, int>
using namespace std;

double size(vec a) {
	return sqrt(a.first * a.first + a.second * a.second);
}

double cross(vec a, vec b) {
	return a.first * b.second - a.second * b.first;
}

int main() {
	int x[3];
	int y[3];

	for (int i = 0; i < 3; i++)
		cin >> x[i] >> y[i];

	vec a = {x[1] - x[0], y[1]- y[0]};
	vec b = { x[2] - x[0], y[2] - y[0] };

	double sa = size(a);
	double sb = size(b);
	double axb = cross(a, b);
	double sin = axb / (sa * sb);

	if (sin > 0)
		cout << 1;
	else if (sin < 0)
		cout << -1;
	else
		cout << 0;

	return 0;
}