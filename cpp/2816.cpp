#include <iostream>
using namespace std;

int N;
string C[101];

void swap(int a, int b) {
    string temp = C[a];
    C[a] = C[b];
    C[b] = temp;
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> C[i];

    int pos;

    // KBS1 찾아서 1번으로 이동
    for (int i = 1; i <= N; i++) {
        if (C[i] == "KBS1") {
            pos = i;
            break;
        }
    }

    for (int i = 1; i < pos; i++)
        cout << "1";

    for (int i = pos; i > 1; i--) {
        cout << "4";
        swap(i, i - 1);
    }

	// KBS2 찾아서 2번으로 이동
    for (int i = 1; i <= N; i++) {
        if (C[i] == "KBS2") {
            pos = i;
            break;
        }
    }

    for (int i = 1; i < pos; i++)
        cout << "1";

    for (int i = pos; i > 2; i--) {
        cout << "4";
        swap(i, i - 1);
    }
        

    return 0;
}