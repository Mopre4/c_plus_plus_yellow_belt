#include <iomanip> 
#include <sstream>
#include <iostream>
#include <vector>
#include <math.h>
#include <memory>


using namespace std;


double S(int a, int b, int c) {
	double p = (a + b + c) / 2.0;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}	
class Figure {
public:
	virtual string Name() const = 0;
	virtual double Perimeter() const = 0;
	virtual double Area() const = 0;

};

class Rect : public Figure {
public:
	Rect(const string name, const int weigth, const int heigth) :
		name_(name), weigth_(weigth), heigth_(heigth) {}	
	string Name() const override{return name_;}
	double Perimeter() const override {return (weigth_ + heigth_) * 2;}
	double Area() const override { return weigth_ * heigth_; }
private:
	const string name_;
	const int weigth_;
	const int heigth_;
};

class Triangle : public Figure {
public:
	Triangle(const string name, const int a, const int b, const int c) :
		name_(name), a_(a), b_(b), c_(c){}
	string Name() const override { return name_; }
	double Perimeter() const override { return a_ + b_ + c_; }
	double Area() const override { return S(a_, b_, c_); }

private:
	const string name_;
	const int a_, b_, c_;
};

class Circle : public Figure {
public:
	Circle(const string name, const int r) : name_(name), r_(r) {}
	string Name() const override { return name_; }
	double Perimeter() const override { return 2 * 3.14 * r_; }
	double Area() const override {return 3.14*r_*r_; }
private:
	const string name_;
	const int r_;
};

shared_ptr<Figure> CreateFigure(istringstream& is) {
	string figure_type;
	is >> figure_type;
	if (figure_type == "RECT") {
		int weidth, height;
		is >> weidth >> height;
		return make_shared<Rect>(figure_type, weidth, height);
	}
	else if (figure_type == "TRIANGLE") {
		int a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(figure_type, a, b, c);
	}
	else if (figure_type == "CIRCLE" || figure_type == "Circle") {
		int r;
		is >> r;
		return make_shared<Circle>(figure_type, r);
	}
}
int main() {
	vector<shared_ptr<Figure>> figures;
	for (string line; getline(cin, line); ) {
		istringstream is(line);

		string command;
		is >> command;
		if (command == "ADD") {
			// Пропускаем "лишние" ведущие пробелы.
			// Подробнее об std::ws можно узнать здесь:
			// https://en.cppreference.com/w/cpp/io/manip/ws
			is >> ws;
			figures.push_back(CreateFigure(is));
		}
		else if (command == "PRINT") {
			for (const auto& current_figure : figures) {
				cout << fixed << setprecision(3)
					<< current_figure->Name() << " "
					<< current_figure->Perimeter() << " "
					<< current_figure->Area() << endl;
			}
		}
	}
	return 0;
}