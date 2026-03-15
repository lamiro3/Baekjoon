#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char vowel[] = { 'a', 'e', 'i', 'o', 'u' };

int main() {
	string s;

	while (getline(cin, s)) {
		if (s == "end")
			break;

		int vowelCnt = 0;
		bool isOK = true;
		bool isVowel[20] = { false };

		for (int i = 0; i < s.size(); i++) {
			if (find(vowel, vowel + 5, s[i]) != vowel + 5) {
				isVowel[i] = true;
			}
		}

		for (int i = 0; i < s.size(); i++) {
			if (isVowel[i]) {
				vowelCnt++;
			}
		}

		if (vowelCnt == 0) {
			isOK = false;
		}
		
		for (int i = 2; i < s.size() && isOK; i++) {
			if (!isVowel[i] && !isVowel[i - 1] && !isVowel[i - 2]) {
				isOK = false;
				break;
			}

			else if (isVowel[i] && isVowel[i - 1] && isVowel[i - 2]) {
				isOK = false;
				break;
			}
		}

		for (int i = 1; i < s.size() && isOK; i++) {
			if (s[i] == s[i - 1] && s[i] != 'e' && s[i] != 'o') {
				isOK = false;
				break;
			}
		}

		cout << "<" << s << ">" << (isOK ? " is acceptable." : " is not acceptable.") << "\n";
	}

	return 0;
}