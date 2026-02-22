//#include <iostream>
//#include <string>
//#include <vector>
//
//using namespace std;
//vector<int> pi;
//
//// 태블릿 KMP 풀이 참고
//void getPi(string tgt) {
//	int size = tgt.size();
//	 pi.assign(size, 0);
//
//	for (int i = 1, j = 0; i < size; i++) {
//		// 
//		while (j > 0 && tgt[i] != tgt[j])
//			j = pi[j - 1];
//
//		if (tgt[i] == tgt[j])
//			pi[i] = j + 1;
//
//		else
//			pi[i] = 0;
//	}
//}
//
//bool KMP(string s, string tgt) {
//	int sLen = s.size();
//	int tgtLen = tgt.size();
//	int j = 0;
//
//	for (int i = 0; i < sLen; i++) {
//		while (j > 0 && s[i] != tgt[j]) {
//			j = pi[j - 1];
//		}
//
//		if (s[i] == tgt[j]) {
//			if (j == tgtLen - 1)
//				return true;
//			else
//				j++;
//		}
//	}
//	return false;
//}
//
//int main() {
//	int n, m, ans = 0;
//	cin >> n >> m;
//	
//	vector<string> S;
//	while (n--) {
//		string s;
//		cin >> s;
//		S.push_back(s);
//	}
//
//	while (m--) {
//		string tgt;
//		cin >> tgt;
//		getPi(tgt);
//
//		for (string s : S) {
//			if (KMP(s, tgt)) {
//				ans++;
//				break;
//			}
//		}
//	}
//
//	cout << ans;
//
//	return 0;
//}

#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    unordered_set<string> S;
    string s;

    while (n--) {
        cin >> s;
        S.insert(s);
    }

    int ans = 0;
    while (m--) {
        cin >> s;
        if (S.find(s) != S.end())
            ans++;
    }

    cout << ans;
}