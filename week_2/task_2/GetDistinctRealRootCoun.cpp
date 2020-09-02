#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <math.h>

using namespace std;


template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
	if (t != u) {
		ostringstream os;
		os << "Assertion failed: " << t << " != " << u;
		if (!hint.empty()) {
			os << " hint: " << hint;
		}
		throw runtime_error(os.str());
	}
}

void Assert(bool b, const string& hint) {
	AssertEqual(b, true, hint);
}

class TestRunner {
public:
	template <class TestFunc>
	void RunTest(TestFunc func, const string& test_name) {
		try {
			func();
			cerr << test_name << " OK" << endl;
		}
		catch (exception & e) {
			++fail_count;
			cerr << test_name << " fail: " << e.what() << endl;
		}
		catch (...) {
			++fail_count;
			cerr << "Unknown exception caught" << endl;
		}
	}

	~TestRunner() {
		if (fail_count > 0) {
			cerr << fail_count << " unit tests failed. Terminate" << endl;
			exit(1);
		}
	}

private:
	int fail_count = 0;
};

int GetDistinctRealRootCount(double a, double b, double c) {
	// Вы можете вставлять сюда различные реализации функции,
	// чтобы проверить, что ваши тесты пропускают корректный код
	// и ловят некорректный
	double D = pow(b, 2) - 4 * a * c;
	if (a != 0) {
		double D = pow(b, 2) - 4 * a * c;
		if (D > 0) {
			return 2;
		}
		else if (D < 0) {
			return 0;
		}
		else return 1;
	}
	else if (b != 0) {  // a = 0, b, c ;  bx + c = 0; x = -c/b; b != 0;
		return 1;
	}
	else return 0;
}

void TwoRoot() {
	AssertEqual(GetDistinctRealRootCount(1, 4, 3), 2);

}
void LinearEq() {
	AssertEqual(GetDistinctRealRootCount(0, 2, 3), 1);
}
void OneRoot() {
	AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1);
}

void NoRealRoots() {
	AssertEqual(GetDistinctRealRootCount(1, 2, 3), 0);
}

void Const() {
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0);
}


int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	runner.RunTest(TwoRoot, "PositivD");
	runner.RunTest(LinearEq, "LinearEq");
	runner.RunTest(OneRoot, "OneRoot");
	runner.RunTest(NoRealRoots, "NoRealRoots");
	runner.RunTest(Const, "Const");

	return 0;
}
