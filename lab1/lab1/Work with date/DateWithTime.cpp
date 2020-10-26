/**
*	@file DateWithTime.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../Work with date/DateWithTime.h"

using namespace std;

istream& operator>>(istream& stream, DateWithTime& DateWithTime_) {
	stream >> DateWithTime_.day;
	stream.ignore(1);
	stream >> DateWithTime_.month;
	stream.ignore(1);
	stream >> DateWithTime_.year;

	stream >> DateWithTime_.hour;
	stream.ignore(1);
	stream >> DateWithTime_.minute;
	stream.ignore(1);
	stream >> DateWithTime_.second;
	return stream;
}

ostream& operator<<(ostream& os, const DateWithTime& DateWithTime_) {
	const string MONTH_NAME[12] = { "January" , "Febuary" , "March" , "April" ,
									 "May" , "June" , "July", "August" , "September" ,
									 "October" , "November" ,  "December" };
	os << setfill('0');
	os << setw(2) << DateWithTime_.day << " " << MONTH_NAME[DateWithTime_.month - 1] << " " << setw(4) << DateWithTime_.year
		<< " ( " << setw(2) << DateWithTime_.hour << ":" << setw(2) << DateWithTime_.minute << ":" << setw(2) << DateWithTime_.second << " ) ";
	return os;
}

bool operator<(const DateWithTime& lhs, const DateWithTime& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} <
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

bool operator>(const DateWithTime& lhs, const DateWithTime& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} >
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

bool operator==(const DateWithTime& lhs, const DateWithTime& rhs) {
	return vector<int>{lhs.year, lhs.month, lhs.day, lhs.hour, lhs.minute, lhs.second} ==
		vector<int>{rhs.year, rhs.month, rhs.day, rhs.hour, rhs.minute, rhs.second};
}

DateWithTime& DateWithTime::operator=(const DateWithTime& right) {
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

