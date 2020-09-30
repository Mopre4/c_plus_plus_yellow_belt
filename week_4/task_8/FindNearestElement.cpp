#include <set>
#include <iostream>
#include <algorithm>


using namespace std;

set<int>::const_iterator FindNearestElement(
	const set<int>& numbers,
	int border) {

	auto it_first = numbers.lower_bound(border);
	if (it_first == numbers.begin()) { 
		return it_first; 
	}

	auto it_second = prev(it_first);

	if (it_first == numbers.end()) {
		return it_second;
	}
	
	if ((abs(border - *(it_first))
		< (abs(border - *(it_second))))) {
		return it_first;
	}
	else return it_second;
	
} 


int main() {
	set<int> numbers = { 1, 4, 6 };
	cout <<
		*FindNearestElement(numbers, 0) << " " <<
		*FindNearestElement(numbers, 3) << " " <<
		*FindNearestElement(numbers, 5) << " " <<
		*FindNearestElement(numbers, 6) << " " <<
		*FindNearestElement(numbers, 100) << endl;

	set<int> empty_set;
	cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
	return 0;
}
