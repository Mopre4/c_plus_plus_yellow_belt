#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <algorithm>

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

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
    for (int i = 0; i < str.size() / 2; ++i) {
        if (str[i] != str[str.size() - i - 1]) {
            return false;
        }
    }
    return true;
}

void EmptyString() {
    AssertEqual(IsPalindrom(""), 1);
    AssertEqual(IsPalindrom("  "), 1);
    AssertEqual(IsPalindrom(" "), 1);
    AssertEqual(IsPalindrom("       "), 1);

}

void oneSymbol() {
    AssertEqual(IsPalindrom("a"), 1);
    AssertEqual(IsPalindrom("A"), 1);
}

void Palindrom_with_space() {
    AssertEqual(IsPalindrom("m a a m"), 1);
    AssertEqual( IsPalindrom(" m a  a m "), 1);
    AssertEqual(IsPalindrom("    a    "), 1);
}

void evenPalindrom() {
    AssertEqual(IsPalindrom("poop"), 1);
    AssertEqual(IsPalindrom("  ABA  "), 1);
    AssertEqual(IsPalindrom("Madam"), 0);
}

void oddPalindrom() {
    AssertEqual(IsPalindrom("pokop"), 1);
    AssertEqual(IsPalindrom("baobab"), 0);
    AssertEqual(IsPalindrom(" ABA") , 0);
}

void even_not_a_Palindrom() {
    AssertEqual(IsPalindrom("damn"), 0);
    AssertEqual(IsPalindrom(" a ba"), 0);
    AssertEqual(IsPalindrom("777777"), 1);

}

void odd_not_a_Palindrom() {
    AssertEqual(IsPalindrom("damnj"), 0);
    AssertEqual(IsPalindrom("ad"), 0);
}



int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(EmptyString, "EmptyString is Palindrom");
    runner.RunTest(oneSymbol, "One Symbol is Palindrom");
    runner.RunTest(Palindrom_with_space, "Palindrom_with_space");
    runner.RunTest(evenPalindrom, "evenPalindrom");
    runner.RunTest(oddPalindrom, "oddPalindrom");
    runner.RunTest(even_not_a_Palindrom, "even_not_a_Palindrom");
    runner.RunTest(odd_not_a_Palindrom, "odd_not_a_Palindrom");
    return 0;
}