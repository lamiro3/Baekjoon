#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Word {
	string s;
	int cnt;
};

// key: 단어, value: 빈도수
map<string, long> howMany;
vector<Word> words;

// 정렬 기준: 1. 빈도수 내림차순, 2. 길이 내림차순, 3. 사전 순 오름차순
bool compare(Word a, Word b) {
	if (a.cnt != b.cnt)
		return a.cnt > b.cnt;

	if (a.s.length() != b.s.length())
		return a.s.length() > b.s.length();

	return a.s < b.s;
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 0; i < n; i++) {
		string s;
		cin >> s;

		// 길이가 m 이상인 단어만 카운트
		if (s.length() >= m) {
			howMany[s]++;
		}
	}

	// 최대한 시간을 줄이기 위해 map에 저장해둔 단어와 빈도수를 벡터로 옮겨서 정렬
	for (auto &p: howMany) {
		words.push_back({p.first, p.second}); // key, value
	}

	sort(words.begin(), words.end(), compare);

	for (auto &word: words)
		cout << word.s << "\n";

	return 0;
}