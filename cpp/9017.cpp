#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> input(N);
        vector<int> cnt(201, 0);

        for (int i = 0; i < N; i++) {
            cin >> input[i];
            cnt[input[i]]++;
        }

        // 유효 팀만 기록
        vector<vector<int>> info(201);
        int rank = 1;

        for (int i = 0; i < N; i++) {
            int team = input[i];

            if (cnt[team] >= 6) {
                info[team].push_back(rank++);
            }
        }

        int winner = -1;
        int bestScore = 1e9;
        int bestFifth = 1e9;

        for (int i = 1; i <= 200; i++) {
            if (info[i].size() < 6) continue;

            int score = 0;
            for (int j = 0; j < 4; j++) {
                score += info[i][j];
            }

            int fifth = info[i][4];

            if (score < bestScore) {
                bestScore = score;
                bestFifth = fifth;
                winner = i;
            }
            else if (score == bestScore) {
                if (fifth < bestFifth) {
                    bestFifth = fifth;
                    winner = i;
                }
            }
        }

        cout << winner << '\n';
    }

    return 0;
}