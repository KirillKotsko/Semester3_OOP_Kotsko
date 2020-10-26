/**
*	@file TimeManagment.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../Work with date/TimeManagment.h"

using namespace std;

TimeManagment::TimeManagment() {
	date_with_time1 = get_current_date_with_time();
	date_with_time2 = get_current_date_with_time();
}

TimeManagment::TimeManagment(const DateWithTime& a, const DateWithTime& b) {
	set_date_with_time(a, 1);
	set_date_with_time(b, 2);
}

TimeManagment::~TimeManagment() {}

bool TimeManagment::check_date_with_time(int num_of_date_with_time) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	bool flag = false;
	if (1 <= chosen_date_with_time.month && chosen_date_with_time.month <= 12) {
		if ((1 <= chosen_date_with_time.day && chosen_date_with_time.day <= DAY_IN_MONTH[chosen_date_with_time.month - 1]) ||
			(chosen_date_with_time.day == 29 && chosen_date_with_time.month == 2 && ((chosen_date_with_time.year % 4 == 0 && chosen_date_with_time.year % 100 != 0) || (chosen_date_with_time.year % 400 == 0)))) {
			if ((0 <= chosen_date_with_time.hour && chosen_date_with_time.hour < 24) && (0 <= chosen_date_with_time.minute && chosen_date_with_time.minute < 60) &&
				(0 <= chosen_date_with_time.second && chosen_date_with_time.second < 60)) {
				flag = true;
			}
		}
	}
	return flag;
}

void TimeManagment::set_date_with_time(const DateWithTime& a, int num_of_date_with_time) {
	if (num_of_date_with_time == 1) {
		date_with_time1 = a;
		if (!check_date_with_time(1)) {
			date_with_time1 = get_current_date_with_time();
		}
	}
	else {
		date_with_time2 = a;
		if (!check_date_with_time(2)) {
			date_with_time2 = get_current_date_with_time();
		}
	}
}

DateWithTime TimeManagment::get_date_with_time(int num_of_date_with_time) {
	if (num_of_date_with_time == 1) return date_with_time1;
	else return date_with_time2;
}

void TimeManagment::show_date_with_time(int num_of_date_with_time) {
	if (num_of_date_with_time == 1) cout << "Date_with_time1: " << date_with_time1 << endl;
	else cout << "Date_with_time2: " << date_with_time2 << endl;
}

// Details: https://lifehacker.ru/kakoj-den-nedeli/.
int TimeManagment::get_weekday_of_date_with_time(int num_of_date_with_time) {
	DateWithTime chosen_date_with_time;

	if (num_of_date_with_time == 0) chosen_date_with_time = get_current_date_with_time();
	else if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	int first_2_number_of_year = chosen_date_with_time.year / 100;
	int last_2_number_of_year = chosen_date_with_time.year % 100;
	int result = (chosen_date_with_time.day + CODE_OF_MONTH[chosen_date_with_time.month - 1] +
		(CODE_OF_YEAR[first_2_number_of_year % 4] + last_2_number_of_year + last_2_number_of_year / 4) % 7) % 7;
	if (((chosen_date_with_time.year % 4 == 0 && chosen_date_with_time.year % 100 != 0) || (chosen_date_with_time.year % 400 == 0)) && (chosen_date_with_time.month <= 2)) result--;
	if (result == -1) result = 6;
	return result;
}

void TimeManagment::day_of_the_week() {
	show_current_date_with_time();
	cout << "Current date_with_time day of the week: " << WEEK_DAY[get_weekday_of_date_with_time(0)] << endl;
	show_date_with_time(1);
	cout << "Date_with_time1 day of the week: " << WEEK_DAY[get_weekday_of_date_with_time(1)] << endl;
	show_date_with_time(2);
	cout << "Date_with_time2 day of the week: " << WEEK_DAY[get_weekday_of_date_with_time(2)] << endl;
}

DifferenceBetweenDateWithTime TimeManagment::get_difference() {
	return minus_for_date_with_times(date_with_time1, date_with_time2);
}

DateWithTime TimeManagment::add_difference(int num_of_date_with_time, DifferenceBetweenDateWithTime to_add) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 0) chosen_date_with_time = get_current_date_with_time();
	else if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	return date_with_time_plus_diff(chosen_date_with_time, to_add);
}

DateWithTime TimeManagment::substract_difference(int num_of_date_with_time, DifferenceBetweenDateWithTime to_substract) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 0) chosen_date_with_time = get_current_date_with_time();
	else if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	return date_with_time_minus_diff(chosen_date_with_time, to_substract);
}

void TimeManagment::show_difference(int mode) {
	DifferenceBetweenDateWithTime to_print = get_difference();
	to_print.change_variant_of_output(mode);
	cout << to_print << endl;
}

void TimeManagment::show_julian_calendar() {
	DifferenceBetweenDateWithTime transfer_days_to_julian = DifferenceBetweenDateWithTime({ from_gregorian_to_julian(get_current_date_with_time()), 0, 0, 0 });
	cout << "Current date_with_time in Julian calendar: " << date_with_time_minus_diff(get_current_date_with_time(), transfer_days_to_julian) << endl;
	transfer_days_to_julian = DifferenceBetweenDateWithTime({ from_gregorian_to_julian(date_with_time1), 0, 0, 0 });
	cout << "Date_with_time1 in Julian calendar: " << date_with_time_minus_diff(date_with_time1, transfer_days_to_julian) << endl;
	transfer_days_to_julian = DifferenceBetweenDateWithTime({ from_gregorian_to_julian(date_with_time2), 0, 0, 0 });
	cout << "DateWithTime2 in Julian calendar: " << date_with_time_minus_diff(date_with_time2, transfer_days_to_julian) << endl;
}

int TimeManagment::week_in_month(int num_of_date_with_time) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 0) chosen_date_with_time = get_current_date_with_time();
	else if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	DifferenceBetweenDateWithTime tmp = minus_for_date_with_times(chosen_date_with_time, DateWithTime({ 1, chosen_date_with_time.month, chosen_date_with_time.year, 0, 0, 0 }));
	tmp.days++;
	int ammount_of_weeks = tmp.days / 7;
	int special_code_of_weekday = get_weekday_of_date_with_time(num_of_date_with_time);
	if (special_code_of_weekday == 0 || special_code_of_weekday == 1) special_code_of_weekday += 6;
	else special_code_of_weekday -= 1;

	if (tmp.days % 7 == 0) {
		if (special_code_of_weekday != 7) ammount_of_weeks++;
	}
	else {
		ammount_of_weeks++;
		if ((tmp.days % 7) > (special_code_of_weekday)) ammount_of_weeks++;
	}
	return ammount_of_weeks;
}

int TimeManagment::week_in_year(int num_of_date_with_time) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 0) chosen_date_with_time = get_current_date_with_time();
	else if (num_of_date_with_time == 1) chosen_date_with_time = date_with_time1;
	else chosen_date_with_time = date_with_time2;

	DifferenceBetweenDateWithTime tmp = minus_for_date_with_times(chosen_date_with_time, DateWithTime({ 1, 1, chosen_date_with_time.year, 0, 0, 0 }));
	tmp.days++;
	int ammount_of_weeks = tmp.days / 7;
	int special_code_of_weekday = get_weekday_of_date_with_time(num_of_date_with_time);
	if (special_code_of_weekday == 0 || special_code_of_weekday == 1) special_code_of_weekday += 6;
	else special_code_of_weekday -= 1;

	if (tmp.days % 7 == 0) {
		if (special_code_of_weekday != 7) ammount_of_weeks++;
	}
	else {
		ammount_of_weeks++;
		if ((tmp.days % 7) > (special_code_of_weekday)) ammount_of_weeks++;
	}
	return ammount_of_weeks;
}

void TimeManagment::alternative_insert_of_date_with_time(int num_of_date_with_time) {
	DateWithTime chosen_date_with_time;
	if (num_of_date_with_time == 0) {
		chosen_date_with_time = get_current_date_with_time();
		cout << "Alternative insert of current date_with_time: ";
	}
	else if (num_of_date_with_time == 1) {
		chosen_date_with_time = date_with_time1;
		cout << "Alternative insert of date_with_time1: ";
	}
	else {
		chosen_date_with_time = date_with_time2;
		cout << "Alternative insert of date_with_time2: ";
	}

	int num_of_weekday = week_in_month(num_of_date_with_time) - 1;
	int special_code_of_weekday = get_weekday_of_date_with_time(num_of_date_with_time);
	if (special_code_of_weekday == 0 || special_code_of_weekday == 1) special_code_of_weekday += 6;
	else special_code_of_weekday -= 1;
	DifferenceBetweenDateWithTime tmp = minus_for_date_with_times(chosen_date_with_time, DateWithTime({ 1, chosen_date_with_time.month, chosen_date_with_time.year, 0, 0, 0 }));
	tmp.days++;
	tmp.days -= special_code_of_weekday;
	if (tmp.days % 7 == 0) num_of_weekday++;
	else if (7 - (tmp.days % 7) < special_code_of_weekday) num_of_weekday++;
	if (num_of_weekday == 0) num_of_weekday = 1;

	string numbers_in_words[5] = { "first", "second", "third", "fourth", "fifth" };
	cout << numbers_in_words[num_of_weekday - 1] << " " << WEEK_DAY[get_weekday_of_date_with_time(num_of_date_with_time)] << " of "
		<< MONTH_NAME[chosen_date_with_time.month - 1] << " " << chosen_date_with_time.year;
	cout << setfill('0');
	cout << " ( " << setw(2) << chosen_date_with_time.hour << ":" << setw(2) << chosen_date_with_time.minute << ":" << setw(2) << chosen_date_with_time.second << " ) " << endl;
}

int TimeManagment::from_gregorian_to_julian(const DateWithTime& date_with_time) {
	if (date_with_time < DateWithTime({ 8, 3, 1300, 0, 0, 0 })) return 7;
	if (DateWithTime({ 7, 3, 1300, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 9, 3, 1400, 0, 0, 0 })) return 8;
	if (DateWithTime({ 8, 3, 1400, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 10, 3, 1500, 0, 0, 0 })) return 9;
	if (DateWithTime({ 9, 3, 1500, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 11, 3, 1700, 0, 0, 0 })) return 10;
	if (DateWithTime({ 10, 3, 1700, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 12, 3, 1800, 0, 0, 0 })) return 11;
	if (DateWithTime({ 11, 3, 1800, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 13, 3, 1900, 0, 0, 0 })) return 12;
	if (DateWithTime({ 12, 3, 1900, 0, 0, 0 }) < date_with_time && date_with_time < DateWithTime({ 14, 3, 2100, 0, 0, 0 })) return 13;
	if (DateWithTime({ 13, 3, 2100, 0, 0, 0 }) < date_with_time) return 14;
}

DifferenceBetweenDateWithTime TimeManagment::minus_for_date_with_times(DateWithTime date_with_time1_, DateWithTime date_with_time2_) {
	DifferenceBetweenDateWithTime result;

	// Ammount days of each month.
	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	// Variable which is used for calculate days difference.
	int sum = 0;
	if (date_with_time2_ < date_with_time1_) swap(date_with_time1_, date_with_time2_);

	// Variant for equal years.
	if (date_with_time1_.year == date_with_time2_.year && date_with_time1_.month != date_with_time2_.month)
	{
		if ((date_with_time1_.year % 4 == 0 && date_with_time1_.year % 100 != 0) || (date_with_time1_.year % 400 == 0)) mounth[1]++;
		sum += date_with_time2_.day + (mounth[date_with_time1_.month - 1] - date_with_time1_.day);
		for (int i = date_with_time1_.month; i < date_with_time2_.month - 1; i++) sum += mounth[i];
		sum--;
		int seconds = date_with_time2_.hour * 3600 + date_with_time2_.minute * 60 + date_with_time2_.second + (86400 - (date_with_time1_.hour * 3600 + date_with_time1_.minute * 60 + date_with_time1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// Variant for equal years and month.
	else if (date_with_time1_.year == date_with_time2_.year && date_with_time1_.month == date_with_time2_.month && date_with_time1_.day != date_with_time2_.day) {
		sum = date_with_time2_.day - date_with_time1_.day;
		sum--;
		int seconds = date_with_time2_.hour * 3600 + date_with_time2_.minute * 60 + date_with_time2_.second + (86400 - (date_with_time1_.hour * 3600 + date_with_time1_.minute * 60 + date_with_time1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// Variant for equal years, month and days.
	else if (date_with_time1_.year == date_with_time2_.year && date_with_time1_.month == date_with_time2_.month && date_with_time1_.day == date_with_time2_.day) {
		int seconds = (date_with_time2_.hour - date_with_time1_.hour) * 3600 + (date_with_time2_.minute - date_with_time1_.minute) * 60 + date_with_time2_.second - date_with_time1_.second;
		result.hour = (seconds / 3600);
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// All others cases.
	else {
		int mounth_ammount_day_year1 = 0;
		for (int i = 0; i < date_with_time1_.month - 1; i++)
		{
			mounth_ammount_day_year1 += mounth[i];
			if (((date_with_time1_.year % 4 == 0 && date_with_time1_.year % 100 != 0) || (date_with_time1_.year % 400 == 0)) && i == 1) mounth_ammount_day_year1++;
		}
		sum += 365 - (date_with_time1_.day + mounth_ammount_day_year1);
		if ((date_with_time1_.year % 4 == 0 && date_with_time1_.year % 100 != 0) || (date_with_time1_.year % 400 == 0)) sum++;
		int mounth_ammount_day_year2 = 0;
		for (int i = 0; i < date_with_time2_.month - 1; i++)
		{
			mounth_ammount_day_year2 += mounth[i];
			if (((date_with_time2_.year % 4 == 0 && date_with_time2_.year % 100 != 0) || (date_with_time2_.year % 400 == 0)) && i == 1) mounth_ammount_day_year2++;
		}
		sum += date_with_time2_.day + mounth_ammount_day_year2;
		int years_ammount_day = 0;
		for (int i = date_with_time1_.year + 1; i < date_with_time2_.year; i++)
		{
			years_ammount_day += 365;
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) years_ammount_day++;
		}
		sum += years_ammount_day;
		sum--;
		int seconds = date_with_time2_.hour * 3600 + date_with_time2_.minute * 60 + date_with_time2_.second + (86400 - (date_with_time1_.hour * 3600 + date_with_time1_.minute * 60 + date_with_time1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	result.days = sum;
	return result;
}

DateWithTime TimeManagment::date_with_time_plus_diff(DateWithTime date_with_time, DifferenceBetweenDateWithTime plus) {
	DateWithTime result = { date_with_time.day, date_with_time.month, date_with_time.year, 0, 0, 0 };

	int days = plus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = date_with_time.hour * 3600 + date_with_time.minute * 60 + date_with_time.second + plus.hour * 3600 + plus.minute * 60 + plus.seconds;
	if (seconds / 3600 >= 24) {
		hour_to_record = (seconds / 3600) - 24;
		days++;
	}
	else hour_to_record = seconds / 3600;
	minute_to_record = (seconds % 3600) / 60;
	seconds_to_record = (seconds % 3600) % 60;
	while (days != 0) {
		DateWithTime to_compare = { 1, result.month % 12 + 1, result.year, 0, 0, 0 };
		if (to_compare.month == 1) to_compare.year++;
		DifferenceBetweenDateWithTime remainder = minus_for_date_with_times(to_compare, result);
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

DateWithTime TimeManagment::date_with_time_minus_diff(DateWithTime date_with_time, DifferenceBetweenDateWithTime minus) {
	DateWithTime result = { date_with_time.day, date_with_time.month, date_with_time.year, 0, 0, 0 };

	// Ammount days of each month.
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };

	int days = minus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = 86400 + (date_with_time.hour * 3600 + date_with_time.minute * 60 + date_with_time.second) - (minus.hour * 3600 + minus.minute * 60 + minus.seconds);
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
		DateWithTime to_compare = { 1, (result.month + 11) % 12, result.year, 0, 0, 0 };
		if (to_compare.month == 0) {
			to_compare.month = 12;
			to_compare.year--;
		}
		to_compare.day = month[to_compare.month - 1];
		DifferenceBetweenDateWithTime remainder = minus_for_date_with_times(result, to_compare);
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

TimeManagment& TimeManagment::operator=(TimeManagment right) {
	if (this == &right) {
		return *this;
	}
	date_with_time1 = right.get_date_with_time(1);
	date_with_time2 = right.get_date_with_time(2);
	return *this;
}
