#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	if ((range_end - range_begin) < 2) {
		return;
	}

	vector<typename RandomIt::value_type> elements(range_begin, range_end);
	
	auto it = elements.begin() + elements.size() / 3;
	auto it2 = elements.begin()+ elements.size()*2 / 3;

	MergeSort(elements.begin(), it);
	MergeSort(it, it2);
	MergeSort(it2, elements.end());

	vector<typename RandomIt::value_type> tmp;

	merge(elements.begin(), it, it, it2, back_inserter(tmp));
	merge(tmp.begin(), tmp.end(), it2, elements.end(), range_begin);
}

int main() {
	vector<int> v = { 6, 4, 7, 6, 4, 4, 0, 1 };
	MergeSort(begin(v), end(v));
	for (int x : v) {
		cout << x << " ";
	}
	cout << endl;
	return 0;
}