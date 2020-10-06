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
	os << setfill('0');
	os << setw(2) << date.day << " " << MONTH_NAME[date.month - 1] << " " << setw(4) << date.year
		<< " ( " << setw(2) << date.hour << ":" << setw(2) << date.minute << ":" << setw(2) << date.second << " ) ";
	return os;
}

ostream& operator<<(ostream& os, const Difference_between_date& info) {
	os << "Difference between date1 and date2 are " << info.days << " days, " << info.hour << " hours, " << info.minute << " minutes, " << info.seconds << " seconds. ";
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

bool operator==(const Difference_between_date& lhs, const Difference_between_date& rhs) {
	return vector<int>{lhs.days, lhs.hour, lhs.minute, lhs.seconds} ==
		vector<int>{rhs.days, rhs.hour, rhs.minute, rhs.seconds};
}

Difference_between_date minus_for_equal_years(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;

	if ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) mounth[1]++;
	sum += date2.day + (mounth[date1.month - 1] - date1.day);
	for (int i = date1.month; i < date2.month - 1; i++) sum += mounth[i];
	sum--;
	int seconds = date2.hour * 3600 + date2.minute * 60 + date2.second + (86400 - (date1.hour * 3600 + date1.minute * 60 + date1.second));
	if (seconds / 3600 >= 24) {
		result.hour = (seconds / 3600) - 24;
		sum++;
	}
	else {
		result.hour = (seconds / 3600);
	}
	result.minute = (seconds % 3600) / 60;
	result.seconds = (seconds % 3600) % 60;

	result.days = sum;
	return result;
}

Difference_between_date minus_for_equal_years_and_month(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;

	sum = date2.day - date1.day;
	sum--;
	int seconds = date2.hour * 3600 + date2.minute * 60 + date2.second + (86400 - (date1.hour * 3600 + date1.minute * 60 + date1.second));
	if (seconds / 3600 >= 24) {
		result.hour = (seconds / 3600) - 24;
		sum++;
	}
	else {
		result.hour = (seconds / 3600);
	}
	result.minute = (seconds % 3600) / 60;
	result.seconds = (seconds % 3600) % 60;

	result.days = sum;
	return result;
}

Difference_between_date minus_for_equal_dates(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;

	int seconds = (date2.hour - date1.hour) * 3600 + (date2.minute - date1.minute) * 60 + date2.second - date1.second;
	result.hour = (seconds / 3600);
	result.minute = (seconds % 3600) / 60;
	result.seconds = (seconds % 3600) % 60;

	result.days = sum;
	return result;
}

Difference_between_date minus_for_no_equals(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;

	int mounth_ammount_day_year1 = 0;
	for (int i = 0; i < date1.month - 1; i++)
	{
		mounth_ammount_day_year1 += mounth[i];
		if (((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) && i == 1) mounth_ammount_day_year1++;
	}
	sum += 365 - (date1.day + mounth_ammount_day_year1);
	if ((date1.year % 4 == 0 && date1.year % 100 != 0) || (date1.year % 400 == 0)) sum++;
	int mounth_ammount_day_year2 = 0;
	for (int i = 0; i < date2.month - 1; i++)
	{
		mounth_ammount_day_year2 += mounth[i];
		if (((date2.year % 4 == 0 && date2.year % 100 != 0) || (date2.year % 400 == 0)) && i == 1) mounth_ammount_day_year2++;
	}
	sum += date2.day + mounth_ammount_day_year2;
	int years_ammount_day = 0;
	for (int i = date1.year + 1; i < date2.year; i++)
	{
		years_ammount_day += 365;
		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) years_ammount_day++;
	}
	sum += years_ammount_day;
	sum--;
	int seconds = date2.hour * 3600 + date2.minute * 60 + date2.second + (86400 - (date1.hour * 3600 + date1.minute * 60 + date1.second));
	if (seconds / 3600 >= 24) {
		result.hour = (seconds / 3600) - 24;
		sum++;
	}
	else {
		result.hour = (seconds / 3600);
	}
	result.minute = (seconds % 3600) / 60;
	result.seconds = (seconds % 3600) % 60;

	result.days = sum;
	return result;
}

Difference_between_date operator-(Date date1, Date date2) {
	Difference_between_date result;

	if (date2 < date1) swap(date1, date2);

	if (date1.year == date2.year && date1.month != date2.month) return minus_for_equal_years(date1, date2);
	else if (date1.year == date2.year && date1.month == date2.month && date1.day != date2.day) return minus_for_equal_years_and_month(date1, date2);
	else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) return minus_for_equal_dates(date1, date2);
	else return minus_for_no_equals(date1, date2);
}

Date operator+(Date date, Difference_between_date plus) {
	Date result = { date.day, date.month, date.year, 0, 0, 0 };

	int days = plus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = date.hour * 3600 + date.minute * 60 + date.second + plus.hour * 3600 + plus.minute * 60 + plus.seconds;
	if (seconds / 3600 >= 24) {
		hour_to_record = (seconds / 3600) - 24;
		days++;
	}
	else hour_to_record = seconds / 3600;
	minute_to_record = (seconds % 3600) / 60;
	seconds_to_record = (seconds % 3600) % 60;
	while (days != 0) {
		Date to_compare = { 1, result.month % 12 + 1, result.year, 0, 0, 0 };
		if (to_compare.month == 1) to_compare.year++;
		Difference_between_date remainder = to_compare - result;
		if (remainder.days <= days) {
			result = to_compare;
			days -= remainder.days;
		}
		else {
			result.day += days;
			days = 0;
		}
	}
	result.hour = hour_to_record;
	result.minute = minute_to_record;
	result.second = seconds_to_record;
	return result;
}

Date operator-(Date date, Difference_between_date minus) {
	Date result = { date.day, date.month, date.year, 0, 0, 0 };

	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };

	int days = minus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = 86400 + (date.hour * 3600 + date.minute * 60 + date.second) - (minus.hour * 3600 + minus.minute * 60 + minus.seconds);
	if (seconds < 86400) {
		hour_to_record = (seconds / 3600);
		days++;
	}
	else {
		seconds -= 86400;
		hour_to_record = (seconds / 3600);
	}
	minute_to_record = (seconds % 3600) / 60;
	seconds_to_record = (seconds % 3600) % 60;
	while (days != 0) {
		if ((result.year % 4 == 0 && result.year % 100 != 0) || (result.year % 400 == 0)) month[1] = 29;
		else month[1] = 28;
		Date to_compare = { 1, (result.month + 11) % 12, result.year, 0, 0, 0 };
		if (to_compare.month == 0) {
			to_compare.month = 12;
			to_compare.year--;
		}
		to_compare.day = month[to_compare.month - 1];
		Difference_between_date remainder = result - to_compare;
		if (remainder.days <= days) {
			result = to_compare;
			days -= remainder.days;
		}
		else {
			result.day -= days;
			days = 0;
		}
	}
	result.hour = hour_to_record;
	result.minute = minute_to_record;
	result.second = seconds_to_record;
	return result;
}