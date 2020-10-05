#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
	Person(const string& name, const string& occupation) :
		name_(name), occupation_(occupation) {}

	string GetName() const {return name_;}
	string GetOccupation() const {return occupation_;}
	virtual void Walk(const string& destination) const {
		cout << occupation_ << " " << name_ << " walks to: " << destination << endl;
	};

private:
	const string name_;
	const string occupation_;
};

class Student : public Person {
public:
	Student(string name, string favouriteSong) : 
			Person(name, "Student"), 
			FavouriteSong(favouriteSong){}

	void Learn() {
		cout << GetOccupation() << " " << GetName() << " learns" << endl;
	}

	void Walk(const string& destination) const override {
		Person::Walk(destination);
		cout << GetOccupation() << " " << GetName() << " sings a song: " << FavouriteSong << endl;
	}


public:
	const string FavouriteSong;
};


class Teacher:public Person {
public:

	Teacher(const string& name, const string& subject) : 
			Person(name, "Teacher"), Subject_(subject) {}

	void Teach() {
		cout << GetOccupation() << " " << GetName() << " teaches: " << Subject_ << endl;
	}



public:
	const string Subject_;
};


class Policeman : public Person {
public:
	Policeman(const string& name) : Person(name, "Policeman") {}

	void Check(Person& person) {
		cout << "Policeman: " << person.GetName() << " checks " << person.GetOccupation()
			<< person.GetOccupation() << "'s name is:" << person.GetName() << endl;
	}

};


void VisitPlaces(Person &person, vector<string> places) {
	for (auto place : places) {
		person.Walk(place);
	}
}


int main() {
	Teacher t("Jim", "Math");
	Student s("Ann", "We will rock you");
	Policeman p("Bob");

	VisitPlaces(t, { "Moscow", "London" });
	p.Check(s);
	VisitPlaces(s, { "Moscow", "London" });
	return 0;
}
