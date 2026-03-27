#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dices[10];
int horse_pos[4] = { 0, 0, 0, 0 }; // 말들의 현재 '인덱스'
int ans = 0;

// 맵 정보 정의
int board[33];      // board[i]: i번 인덱스에서 한 칸 이동 시 도착하는 인덱스
int blue[33];       // blue[i]: i번 인덱스가 파란색 칸일 때 이동하는 지름길 인덱스
int score[33];      // score[i]: i번 인덱스의 점수
bool isOccupied[33]; // 해당 인덱스에 말이 있는지 확인

void init() {
    // 1. 메인 라인 (0~20번 인덱스: 0점부터 40점까지)
    for (int i = 0; i <= 19; i++) board[i] = i + 1;

    board[20] = 32; // 20번(40점) 다음은 32번(도착점)
    for (int i = 0; i <= 20; i++) score[i] = i * 2;

    // 2. 지름길 설정
    // 5번(10점)에서 시작
    blue[5] = 21;
    score[21] = 13; score[22] = 16; score[23] = 19;
    board[21] = 22; board[22] = 23; board[23] = 24;

    // 10번(20점)에서 시작
    blue[10] = 25;
    score[25] = 22; score[26] = 24;
    board[25] = 26; board[26] = 24;

    // 15번(30점)에서 시작
    blue[15] = 27;
    score[27] = 28; score[28] = 27; score[29] = 26;
    board[27] = 28; board[28] = 29; board[29] = 24;

    // 3. 중앙 합류 지점 (25, 30, 35, 40)
    score[24] = 25; score[30] = 30; score[31] = 35;
    board[24] = 30; board[30] = 31; board[31] = 20; // 35점 다음은 40점(20번)

    // 4. 도착 지점
    score[32] = 0;
    board[32] = 32;
}

void solve(int dice_idx, int total_score) {
    if (dice_idx == 10) {
        ans = max(ans, total_score);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int cur = horse_pos[i];
        if (cur == 32) continue; // 이미 도착한 말은 스킵

        int next = cur;
        // 첫 이동 시 파란색 칸이면 지름길로
        if (blue[next] != 0) {
            next = blue[next];
        }
        else {
            next = board[next];
        }

        // 남은 주사위 눈만큼 이동
        for (int d = 1; d < dices[dice_idx]; d++) {
            next = board[next];
        }

        // 도착점이 아닌데 이미 다른 말이 있다면 못 감
        if (next != 32 && isOccupied[next]) continue;

        // 백트래킹
        int prev_pos = horse_pos[i];
        isOccupied[prev_pos] = false;
        isOccupied[next] = true;
        horse_pos[i] = next;

        solve(dice_idx + 1, total_score + score[next]);

        // 원상 복구
        horse_pos[i] = prev_pos;
        isOccupied[next] = false;
        isOccupied[prev_pos] = true;
    }
}

int main() {
    for (int i = 0; i < 10; i++) 
        cin >> dices[i];

    init();
    solve(0, 0);

    cout << ans << endl;
    return 0;
}