#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(){
	int x, N;
	cin >> x >> N;
	deque<string>ready_expression;
	ready_expression.push_back(to_string(x));
	string req;
	for (int i = 0; i != N; i++) {
		cin >> req >> x;
		ready_expression.push_front("(");
		ready_expression.push_back(")");
		ready_expression.push_back(" " +req +" ");
		ready_expression.push_back(to_string(x));
	}

	for (auto& nums : ready_expression) {
		cout << nums;
	}

	return 0;
}
