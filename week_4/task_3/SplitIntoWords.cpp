
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
//#include <cctype>

using namespace std;
vector<string> SplitIntoWords(const string& s) {
	vector<string> res;
	for (auto it = s.begin(); it != s.end(); ++it) {
		auto it_space = find_if(it, s.end(), [](char ch) {
			return isspace(ch);
			});
		res.push_back({ it, it_space });
		it = it_space;
		if (it_space == s.end()) {
			break;
		}
	}
	return res;
}

int main() {
	string s = "C Cpp Java Python";

	vector<string> words = SplitIntoWords(s);
	cout << words.size() << " ";
	for (auto it = begin(words); it != end(words); ++it) {
		if (it != begin(words)) {
			cout << "/";
		}
		cout << *it;
	}
	cout << endl;

	return 0;
}