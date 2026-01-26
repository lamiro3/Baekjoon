#include<iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int N; cin >> N;
    vector <int> A(N);
    for (int& i : A) cin >> i;

    int M; cin >> M;
    vector <tuple <int, int, int>> info(M);
    for (auto& [L, R, C] : info)
    {
        cin >> L >> R >> C;
        L--, R--;
    }

    // 최소 비용, 해당 상태
    // 최대 힙 -> 최소 비용 먼저 꺼내기 위해 cost를 음수로 저장
    priority_queue <pair<int, vector <int>>> pq;
    map <vector <int>, int> dist;

    // 맨 처음 상태  = 0
    for (pq.push({ dist[A] = 0, A }); pq.size();)
    {
        auto [cost, now](pq.top()); pq.pop();
        if (dist[now] >= -cost) // 현재 상태가 최저 비용이라면
            // 가능한 조작 모두 수행
            for (auto& [L, R, C] : info)
            {
                swap(now[L], now[R]);

                // 조작 후 상태가 아직 방문 못했거나, 기존보다 더 저렴하게 도달 가능하다면
                if (!dist.count(now) || dist[now] > C - cost)
                    // 최대 힙이므로 음수로 저장
                    pq.push({ -(dist[now] = C - cost), now });
                // 다음 case 계산 위해 다시 원상 복구
                swap(now[L], now[R]);
            }
    }

    sort(A.begin(), A.end());
    cout << (dist.count(A) ? dist[A] : -1);

    return 0;
}