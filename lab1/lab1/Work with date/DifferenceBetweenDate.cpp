/**
*	@file DifferenceBetweenDate.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../Work with date/DifferenceBetweenDate.h"

using namespace std;

bool operator==(const DifferenceBetweenDate& lhs, const DifferenceBetweenDate& rhs) {
	return vector<int>{lhs.days, lhs.hour, lhs.minute, lhs.seconds} ==
		vector<int>{rhs.days, rhs.hour, rhs.minute, rhs.seconds};
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

void DifferenceBetweenDate::change_variant_of_output(int choice) {
	variant_of_output = choice;
}