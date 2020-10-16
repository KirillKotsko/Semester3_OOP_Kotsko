/**
*	@file Date.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../Work with date/Date.h"

using namespace std;

istream& operator>>(istream& stream, Date& date) {
	stream >> date.day;
	stream.ignore(1);
	stream >> date.month;
	stream.ignore(1);
	stream >> date.year;

	stream >> date.hour;
	stream.ignore(1);
	stream >> date.minute;
	stream.ignore(1);
	stream >> date.second;
	return stream;
}

ostream& operator<<(ostream& os, const Date& date) {
	const string MONTH_NAME[12] = { "January" , "Febuary" , "March" , "April" ,
									 "May" , "June" , "July", "August" , "September" ,
									 "October" , "November" ,  "December" };
	os << setfill('0');
	os << setw(2) << date.day << " " << MONTH_NAME[date.month - 1] << " " << setw(4) << date.year
		<< " ( " << setw(2) << date.hour << ":" << setw(2) << date.minute << ":" << setw(2) << date.second << " ) ";
	return os;
}

bool operator<(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} <
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

bool operator>(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} >
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

bool operator==(const Date& lhs, const Date& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} ==
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

Date& Date::operator=(const Date& right) {
	if (this == &right) {
		return *this;
	}
	day = right.day;
	month = right.month;
	year = right.year;
	hour = right.hour;
	minute = right.minute;
	second = right.second;
	return *this;
}

