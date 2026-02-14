#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// 최대 50글자 숫자 50개를 더하므로, 여유 있게 60~70
const int MAXL = 65;

int charToVal(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    return c - 'A' + 10;
}

char valToChar(int v) {
    if (v < 10) return (char)(v + '0');
    return (char)(v - 10 + 'A');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> nums(N);
    // gain[문자번호][자릿수]: 해당 문자를 Z로 바꿨을 때 얻는 자릿수별 이득 합계
    vector<vector<int>> gain(36, vector<int>(MAXL, 0));

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
        int len = nums[i].size();
        for (int j = 0; j < len; j++) {
            int val = charToVal(nums[i][len - 1 - j]);
            int diff = 35 - val; // Z(35)로 바꿨을 때의 차이
            gain[val][j] += diff;
        }
    }

    // 각 문자의 gain에 대해 36진수 올림 처리를 미리 수행 (비교를 위해 필수)
    for (int i = 0; i < 36; i++) {
        for (int j = 0; j < MAXL - 1; j++) {
            gain[i][j + 1] += gain[i][j] / 36;
            gain[i][j] %= 36;
        }
    }

    // 정렬을 위한 인덱스 배열
    vector<int> order(36);
    for (int i = 0; i < 36; i++) order[i] = i;

    // 이득이 큰 순서대로 내림차순 정렬
    sort(order.begin(), order.end(), [&](int a, int b) {
        for (int i = MAXL - 1; i >= 0; i--) {
            if (gain[a][i] != gain[b][i])
                return gain[a][i] > gain[b][i];
        }
        return false;
        });

    int K;
    cin >> K;

    // 상위 K개의 문자를 'Z'로 치환하기 위해 표시
    vector<bool> shouldChange(36, false);
    for (int i = 0; i < min(K, 36); i++) {
        shouldChange[order[i]] = true;
    }

    // 최종 합계 계산 (큰 수 덧셈)
    vector<int> totalSum(MAXL, 0);
    for (int i = 0; i < N; i++) {
        int len = nums[i].size();
        for (int j = 0; j < len; j++) {
            int val = charToVal(nums[i][len - 1 - j]);
            if (shouldChange[val]) val = 35;
            totalSum[j] += val;
        }
    }

    // 전체 합계에 대한 올림 처리
    for (int i = 0; i < MAXL - 1; i++) {
        totalSum[i + 1] += totalSum[i] / 36;
        totalSum[i] %= 36;
    }

    // 출력 (가장 높은 자릿수부터)
    int start = MAXL - 1;
    while (start > 0 && totalSum[start] == 0) start--;

    for (int i = start; i >= 0; i--) {
        cout << valToChar(totalSum[i]);
    }
    cout << endl;

    return 0;
}