#include <iostream>
#include <vector>
#include <map>
#include <tuple>
using namespace std;


// Предварительное объявление шаблонных функций
//template<typename T> T Sqr(T x);
//template<typename T> void FuncB(T x);


template<typename T>
T Sqr(T value);


template<typename T>
vector<T> Sqr(const vector<T>& value);

template<typename k, typename v>
map<k, v> Sqr(const map<k, v>& value);


template<typename f, typename s>
pair<f, s> Sqr(const pair<f, s>& value);

template <typename T>
T Sqr(T x) {
	return x * x;
}

template<typename T>
vector<T> Sqr(const vector<T>& x) {
	vector<T> res;
	for (const auto &item : x) {
		res.push_back(Sqr(item));
	}
	return res;
}


template <typename k, typename v>
map <k, v> Sqr(const map<k, v>& m) {
	map<k, v> res;
	for (const auto& item : m) {
		res[item.first] = Sqr(item.second);
	}
	return res;
}


template <typename f, typename s>
pair<f, s> Sqr(const pair <f, s>& val) {
	return make_pair(Sqr(val.first), Sqr(val.second));
}


int main()
{
	// Пример вызова функции
	vector<int> v = { 1, 2, 3 };
	cout << "vector:";
	for (int x : Sqr(v)) {
		cout << ' ' << x;
	}
	cout << endl;
	
	map<int, pair<int, int>> map_of_pairs = {
	  {4, {2, 2}},
	  {7, {4, 3}}
	};
	cout << "map of pairs:" << endl;
	for (const auto& x : Sqr(map_of_pairs)) {
		cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
	}
	return 0;
}
