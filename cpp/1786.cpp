#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long> getFail(string s) {
	int size = s.size();
	vector<long> fail(size, 0);

	int i = 1, j = 0;

	while (i + j < size) {
		if (s[i + j] == s[j]) {
			j++;
			fail[i + j - 1] = j;
		}

		else {
			if (j == 0)
				i++;

			else {
				i += j - fail[j - 1];
				j = fail[j - 1];
			}
		}
	}

	return fail;
}

void kmp(string s1, string s2) {
    long j = 0;
    long i = 0;

    vector<long> ans;
    vector<long> fail = getFail(s2);

    while (i + j < s1.size()) {
        if (s1[i + j] == s2[j]) {
            j++;
            if (j == s2.size()) {
                ans.push_back(i+1);
                i += j - fail[j - 1];
                j = fail[j - 1];
            }
        }
        else {
            if (j == 0)
                i++;
            else {
                i += j - fail[j - 1];
                j = fail[j - 1];
            }
        }
    }

    cout << ans.size() << "\n";
    for (int k = 0; k < ans.size(); k++) {
        cout << ans[k] << " ";
    }
}

int main() {
	string T, P;
	
	getline(cin, T);
	getline(cin, P);
	
	kmp(T, P);

	return 0;
}