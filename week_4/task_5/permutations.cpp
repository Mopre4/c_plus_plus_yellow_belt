#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main() {

	size_t n;
	cin >> n;
	vector<int> v;
	for (size_t i = 1; i <= n; i++) {
		v.push_back(i);
	}

	reverse(v.begin(), v.end());

	do {
		for (auto& x : v) {
			cout << x << ' ';
		} cout << endl;
	} while (prev_permutation(v.begin(), v.end()));
}