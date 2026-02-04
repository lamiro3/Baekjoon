#include <iostream>
#include <vector>
#include <functional>
#include <map>


#define LL long long
using namespace std;

int main() {
    LL N, ans = 0;
    cin >> N;

    // 오름차순 정렬
    map<LL, LL, std::less<>> X;
    vector<LL> I;

    for (int i=0; i < N; i++)
    {
        int a;
        cin >> a;

        I.push_back(a); // 입력값 저장
        X.insert({ a, 0 }); // { Xi, X'i }
    }

    for (auto& x : X)
        x.second = ans++; // min은 0 -> +1 씩

    for (auto i : I)
        cout << X[i] << " ";

    return 0;
}
