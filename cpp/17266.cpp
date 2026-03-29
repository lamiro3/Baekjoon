#include <iostream>
#include <algorithm>
using namespace std;

int ceil_dist(int a, int b) {
    return (b - a + 1) / 2; // 올림
}

int main() {
    int n, m;
    cin >> n >> m;

    int prev, now;
    int ans = 0;

    cin >> prev;
    ans = prev;

    for (int i = 1; i < m; i++) {
        cin >> now;
        ans = max(ans, ceil_dist(prev, now));
        prev = now;
    }

    // 마지막 가로등 ~ 도착점
    ans = max(ans, n - prev);

    cout << ans;
}