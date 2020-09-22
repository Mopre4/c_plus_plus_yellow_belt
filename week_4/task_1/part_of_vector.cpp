#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto it_first_negative = find_if(
		begin(numbers), end(numbers), [](int number) {
			return number < 0;
		});
	if (it_first_negative != end(numbers)) {
		while (it_first_negative != begin(numbers)) {
			--it_first_negative;
			cout << *it_first_negative << " ";
		}
	}
	else {
		auto it_last_number = end(numbers);
		while (it_last_number != begin(numbers)) {
			--it_last_number;
			cout << *it_last_number << " ";
		}
	}


}

int main() {
	PrintVectorPart({ 6, 1, 8, -5, 4 });
	cout << endl;
	PrintVectorPart({ -6, 1, 8, -5, 4 });  // ничего не выведется
	cout << endl;
	PrintVectorPart({ 6, 1, 8, 5, 4 });
	cout << endl;
	return 0;
}