/**
*	@file Overload.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/

#include "../HeaderFiles/Date/Date.h"

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

ostream& operator<<(ostream& os, const DifferenceBetweenDate& info) {
	os << "Difference between date1 and date2 are ";
	if (info.variant_of_output == 0)
		os << info.days << " days, " << info.hour << " hours, " << info.minute << " minutes, " << info.seconds << " seconds. ";
	else if (info.variant_of_output == 1)
		os << info.hour + info.days * 24 << " hours, " << info.minute << " minutes, " << info.seconds << " seconds. ";
	else if (info.variant_of_output == 2)
		os << info.minute + info.hour * 60 + info.days * 24 * 60 << " minutes, " << info.seconds << " seconds. ";
	else if (info.variant_of_output == 3)
		os << info.seconds + info.minute * 60 + info.hour * 60 * 60 + info.days * 24 * 60 * 60 << " seconds. ";
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

bool operator==(const DifferenceBetweenDate& lhs, const DifferenceBetweenDate& rhs) {
	return vector<int>{lhs.days, lhs.hour, lhs.minute, lhs.seconds} ==
		vector<int>{rhs.days, rhs.hour, rhs.minute, rhs.seconds};
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

DifferenceBetweenDate& DifferenceBetweenDate::operator=(const DifferenceBetweenDate& right) {
	if (this == &right) {
		return *this;
	}
	days = right.days;
	hour = right.hour;
	minute = right.minute;
	seconds = right.seconds;
	return *this;
}

TimeManagment& TimeManagment::operator=(TimeManagment right) {
	if (this == &right) {
		return *this;
	}
	date1 = right.get_date(1);
	date2 = right.get_date(2);
	return *this;
}

void DifferenceBetweenDate::change_variant_of_output(int choice) {
	variant_of_output = choice;
}

