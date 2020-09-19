#include "sum_reverse_sort.h"
#include <iostream>
#include <algorithm>



int Sum(int x, int y) {
	return x + y;
}

string Reverse(string str) {
	reverse(str.begin(), str.end());
	return str;
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}

//int main()
//{
//}
//
