#include "phone_number.h"
#include "sstream"
#include <iostream>





PhoneNumber::PhoneNumber(const string& international_number) {
	stringstream input_phone(international_number);
	input_phone.ignore(1);
	getline(input_phone, country_code_, '-');
	getline(input_phone, city_code_, '-');
	getline(input_phone, local_number_);

	input_phone.clear(); //!!!

	if (international_number[0] != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty()) {
		throw invalid_argument("");
	}
}

string PhoneNumber::GetCountryCode()const {
	return country_code_;
}

string PhoneNumber::GetCityCode() const{
	return city_code_;
}

string PhoneNumber::GetLocalNumber()const {
	return local_number_;
}

string PhoneNumber::GetInternationalNumber() const {
	return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}

/*
int main()
{
	PhoneNumber number("+7-495-111-22-33");
	cout << number.GetInternationalNumber();

	return 0;
}
*/
