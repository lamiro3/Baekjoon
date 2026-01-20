#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/* 1<= N, M <=9 ~ 값이 크지 않으므로 O(N^4 ~ N^5)여도 ㄱㅊ*/

int N, M;
// 제곱수가 없었다면 -1 출력
long long ans = -1;
vector<string> arr;

int main() {
	cin >> N >> M;
	arr.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int sr = 0; sr<N; sr++){ // 시점 행
		for (int sc = 0; sc < M; sc++) { // 시점 열
			for (int rgap = -N; rgap <= N; rgap++) { // 행 이동 간격
				for (int cgap = -M; cgap <= M; cgap++) { // 열 이동 간격
					// 두 간격 모두 0이면 무한 loop -> 예외 처리
					if (rgap == 0 && cgap == 0)
						continue;

					int r = sr, c = sc;
					string temp;
					
					// 범위 벗어나기 전까지 등차간격 이동
					while (0 <= r && r < N && 
						0 <= c && c < M) {
						temp.push_back(arr[r][c]);
						r += rgap;
						c += cgap;

						long long n = stoll(temp);
						long long rootn = sqrtl(n);

						// 제곱근 값이 정수라면, 정답 갱신
						if (rootn*rootn == n)
							ans = max(ans, n);
					}
				}
			}
		}
	}
	cout << ans;
	return 0;
}