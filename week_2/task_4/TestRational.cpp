#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
	os << "{";
	bool first = true;
	for (const auto& x : s) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << x;
	}
	return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
	os << "{";
	bool first = true;
	for (const auto& kv : m) {
		if (!first) {
			os << ", ";
		}
		first = false;
		os << kv.first << ": " << kv.second;
	}
	return os << "}";
}

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

class Rational {
public:
	Rational() {
		numerator = 0;
		denominator = 1;
	}
	Rational(int new_numerator, int new_denominator) {
		// Реализуйте конструктор
		int tmp = gcd(new_numerator, new_denominator);
		numerator = new_numerator / tmp;
		denominator = new_denominator / tmp;
		if (numerator == 0) {
			denominator = 1;
		}
		else if (numerator < 0 && denominator < 0) {
			numerator = abs(numerator);
			denominator = abs(denominator);
		}
		else if (numerator > 0 && denominator < 0) {
			numerator = -numerator;
			denominator = abs(denominator);
		}
	}
	int Numerator() const {
		// Реализуйте этот метод
		return numerator;
	}
	int Denominator() const {
		// Реализуйте этот метод
		return denominator;
	}
private:
	// Добавьте поля
	int numerator;
	int denominator;
};


void DefaultRational() {
	Rational r;
	AssertEqual(r.Numerator(), 0, "numerator = 0");
	AssertEqual(r.Denominator(), 1, "denominator = 1");

}

void ReduceFraction() {
	Rational r(2, 4);
	AssertEqual(r.Numerator(), 1, "numerator = 1");
	AssertEqual(r.Denominator(), 2, "denominator = 2");
}

void nonReduceFraction() {
	Rational r(1, 3);
	AssertEqual(r.Numerator(), 1, "numerator = 1");
	AssertEqual(r.Denominator(), 3, "denominator = 2");
}

void NegativeFraction() {
	Rational r(-2, 4);
	AssertEqual(r.Numerator(), -1, "Numerator = -1");
	AssertEqual(r.Denominator(), 2, "Denominator = 2");
	Rational r1(2, -4);
	AssertEqual(r1.Numerator(), -1, "Numerator = -1");
	AssertEqual(r1.Denominator(), 2, "Denominator = 2");
	Rational r2(0, -1);
	AssertEqual(r2.Numerator(), 0, "Numerator = 0");
	AssertEqual(r2.Denominator(), 1, "Denominator = 1");

}

void PositiveFraction() {
	Rational r(2, 6);
	AssertEqual(r.Numerator(), 1, "Numerator = 1");
	AssertEqual(r.Denominator(), 3, "Denominator = 3");
}

int main() {
	TestRunner runner;
	runner.RunTest(DefaultRational, "DefaultRational");
	runner.RunTest(ReduceFraction, "ReduceFractional");
	runner.RunTest(NegativeFraction, "NegativeFraction");
	runner.RunTest(PositiveFraction, "PositiveFraction");
	runner.RunTest(nonReduceFraction, "nonReduceFraction");
	
	return 0;
}
