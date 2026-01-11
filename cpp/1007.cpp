#include <iostream>
#include <cstring>
#include <vector>
#include <iomanip>
#include <cmath>

#define po pair<int, int>

using namespace std;

int N;
vector<po> points;
double result;
bool visited[20];
bool isEmpty = true; // 첫 번째 결과값 저장 여부

void input() {
	int a, b;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a >> b;
		points.push_back({ a, b });
	}
}


double getMatchLen(bool visited[]) {
	double x = 0;
	double y = 0;

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			x += points[i].first;
			y += points[i].second;
		}
		else {
			x -= points[i].first;
			y -= points[i].second;
		}
	}
	return sqrt(x * x + y * y);
}

void DFS(bool visited[], int idx, int cnt) {
	if (cnt == N / 2) { // 절반 다 골랐으면 (벡터 매칭 완료)
		double len = getMatchLen(visited);
		if (isEmpty) {
			result = len;
			isEmpty = false;
		}

		if (len < result)
			result = len;

		return;
	}

	for (int i = idx; i < N; i++) {
		if (visited[i]) continue; // i번째 점 방문했으면 패스
		visited[i] = true;
		DFS(visited, i, cnt + 1);
		visited[i] = false;
	}
}

int main() {

	int T;
	cin >> T;

	while (T--) {
		input();
		DFS(visited, 0, 0);

		std::cout << std::fixed;
		std::cout << std::setprecision(12);
		std::cout << result << "\n";

		// 다음 테스트케이스를 위해 초기화
		points.clear();
		memset(visited, false, sizeof(visited));
		isEmpty = true;
	}

	return 0;
}