#include <iostream>
#include <string>
using namespace std;


int main(void)
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int N;
    cin >> N;
    while (N--)
    {
        string word;
        cin >> word;
        int len = word.length();

        if (len == 1)
        {
            cout << word << "\n";
            continue;
        }

        cout << word << "\n";
        for (int i = 1; i < len - 1; i++)
        {
            cout << word[i];
            for (int j = 1; j < len - 1; j++)
                cout << ' ';
            cout << word[len - i - 1] << "\n";
        }

        for (int i = len - 1; i >= 0; i--)
            cout << word[i];
        cout << "\n";
    }
}