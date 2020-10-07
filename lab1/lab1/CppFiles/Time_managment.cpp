#include "../HeaderFiles/Date/Date.h"

using namespace std;

Difference_between_date Time_managment::minus_for_dates(Date date1_,Date date2_) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;
	if (date2_ < date1_) swap(date1_, date2_);

	if (date1_.year == date2_.year && date1_.month != date2_.month)
	{
		if ((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) mounth[1]++;
		sum += date2_.day + (mounth[date1_.month - 1] - date1_.day);
		for (int i = date1_.month; i < date2_.month - 1; i++) sum += mounth[i];
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
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
	else if (date1_.year == date2_.year && date1_.month == date2_.month && date1_.day != date2_.day) {
		sum = date2_.day - date1_.day;
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
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
	else if (date1_.year == date2_.year && date1_.month == date2_.month && date1_.day == date2_.day) {
		int seconds = (date2_.hour - date1_.hour) * 3600 + (date2_.minute - date1_.minute) * 60 + date2_.second - date1_.second;
		result.hour = (seconds / 3600);
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	else {
		int mounth_ammount_day_year1 = 0;
		for (int i = 0; i < date1_.month - 1; i++)
		{
			mounth_ammount_day_year1 += mounth[i];
			if (((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) && i == 1) mounth_ammount_day_year1++;
		}
		sum += 365 - (date1_.day + mounth_ammount_day_year1);
		if ((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) sum++;
		int mounth_ammount_day_year2 = 0;
		for (int i = 0; i < date2_.month - 1; i++)
		{
			mounth_ammount_day_year2 += mounth[i];
			if (((date2_.year % 4 == 0 && date2_.year % 100 != 0) || (date2_.year % 400 == 0)) && i == 1) mounth_ammount_day_year2++;
		}
		sum += date2_.day + mounth_ammount_day_year2;
		int years_ammount_day = 0;
		for (int i = date1_.year + 1; i < date2_.year; i++)
		{
			years_ammount_day += 365;
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) years_ammount_day++;
		}
		sum += years_ammount_day;
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
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

Date Time_managment::date_plus_diff(Date date, Difference_between_date plus) {
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
		Difference_between_date remainder = minus_for_dates(to_compare, result);
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

Date Time_managment::date_minus_diff(Date date, Difference_between_date minus) {
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
		Difference_between_date remainder = minus_for_dates(result, to_compare);
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


Time_managment::Time_managment() {
	date1 = get_current_date();
	date2 = get_current_date();
}

Time_managment::Time_managment(const Date& a, const Date& b) {
	set_date(a, 1);
	set_date(b, 2);
}

Time_managment::~Time_managment() {}

bool Time_managment::check_date(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	bool flag = false;
	if (1 <= chosen_date.month && chosen_date.month <= 12) {
		if ((1 <= chosen_date.day && chosen_date.day <= DAY_IN_MONTH[chosen_date.month - 1]) ||
			(chosen_date.day == 29 && chosen_date.month == 2 && ((chosen_date.year % 4 == 0 && chosen_date.year % 100 != 0) || (chosen_date.year % 400 == 0)))) {
			if ((0 <= chosen_date.hour && chosen_date.hour < 24) && (0 <= chosen_date.minute && chosen_date.minute < 60) &&
				(0 <= chosen_date.second && chosen_date.second < 60)) {
				flag = true;
			}
		}
	}
	return flag;
}

void Time_managment::set_date(const Date& a, int num_of_date) {
	if (num_of_date == 1) {
		date1 = a;
		if (!check_date(1)) {
			date1 = get_current_date();
		}
	}
	else {
		date2 = a;
		if (!check_date(2)) {
			date2 = get_current_date();
		}
	}
}

Date Time_managment::get_date(int num_of_date) {
	if (num_of_date == 1) return date1;
	else return date2;
}

void Time_managment::show_date(int num_of_date) {
	if (num_of_date == 1) cout << "Date1: " << date1 << endl;
	else cout << "Date2: " << date2 << endl;
}

int Time_managment::get_weekday_of_date(int num_of_date) {
	Date chosen_date;

	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	int first_2_number_of_year = chosen_date.year / 100;
	int last_2_number_of_year = chosen_date.year % 100;
	int result = (chosen_date.day + CODE_OF_MONTH[chosen_date.month - 1] +
		(CODE_OF_YEAR[first_2_number_of_year % 4] + last_2_number_of_year + last_2_number_of_year / 4) % 7) % 7;
	if (((chosen_date.year % 4 == 0 && chosen_date.year % 100 != 0) || (chosen_date.year % 400 == 0)) && (chosen_date.month <= 2)) result--;
	if (result == -1) result = 6;
	return result;
}

void Time_managment::day_of_the_week() {
	show_current_date();
	cout << "Current date day of the week: " << WEEK_DAY[get_weekday_of_date(0)] << endl;
	show_date(1);
	cout << "Date1 day of the week: " << WEEK_DAY[get_weekday_of_date(1)] << endl;
	show_date(2);
	cout << "Date2 day of the week: " << WEEK_DAY[get_weekday_of_date(2)] << endl;
}

Difference_between_date Time_managment::get_difference() {
	return minus_for_dates(date1, date2);
}

Date Time_managment::add_difference(int num_of_date, Difference_between_date to_add) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return date_plus_diff(chosen_date, to_add);
}

Date Time_managment::substract_difference(int num_of_date, Difference_between_date to_substract) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return date_minus_diff(chosen_date, to_substract);
}

void Time_managment::show_difference() {
	cout << get_difference() << endl;
}

void Time_managment::show_julian_calendar() {
	Difference_between_date transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(get_current_date()), 0, 0, 0 });
	cout << "Current date in Julian calendar: " << date_minus_diff(get_current_date(), transfer_days_to_julian) << endl;
	transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(date1), 0, 0, 0 });
	cout << "Date1 in Julian calendar: " << date_minus_diff(date1, transfer_days_to_julian) << endl;
	transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(date2), 0, 0, 0 });
	cout << "Date2 in Julian calendar: " << date_minus_diff(date2, transfer_days_to_julian) << endl;
}

int Time_managment::week_in_month(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	Difference_between_date tmp = minus_for_dates(chosen_date, Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 }));
	tmp.days++;
	int ammount_of_weeks = tmp.days / 7;
	int special_code_of_weekday = get_weekday_of_date(num_of_date);
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

int Time_managment::week_in_year(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	Difference_between_date tmp = minus_for_dates(chosen_date, Date({ 1, 1, chosen_date.year, 0, 0, 0 }));
	tmp.days++;
	int ammount_of_weeks = tmp.days / 7;
	int special_code_of_weekday = get_weekday_of_date(num_of_date);
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

void Time_managment::alternative_insert_of_date(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) {
		chosen_date = get_current_date();
		cout << "Alternative insert of current date: ";
	}
	else if (num_of_date == 1) {
		chosen_date = date1;
		cout << "Alternative insert of date1: ";
	}
	else {
		chosen_date = date2;
		cout << "Alternative insert of date2: ";
	}

	int num_of_weekday = week_in_month(num_of_date) - 1;
	int special_code_of_weekday = get_weekday_of_date(num_of_date);
	if (special_code_of_weekday == 0 || special_code_of_weekday == 1) special_code_of_weekday += 6;
	else special_code_of_weekday -= 1;
	Difference_between_date tmp = minus_for_dates(chosen_date, Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 }));
	tmp.days++;
	tmp.days -= special_code_of_weekday;
	if (tmp.days % 7 == 0) num_of_weekday++;
	else if (7 - (tmp.days % 7) < special_code_of_weekday) num_of_weekday++;
	if (num_of_weekday == 0) num_of_weekday = 1;

	string numbers_in_words[5] = { "first", "second", "third", "fourth", "fifth" };
	cout << numbers_in_words[num_of_weekday - 1] << " " << WEEK_DAY[get_weekday_of_date(num_of_date)] << " of "
		<< MONTH_NAME[chosen_date.month - 1] << " " << chosen_date.year;
	cout << setfill('0');
	cout << " ( " << setw(2) << chosen_date.hour << ":" << setw(2) << chosen_date.minute << ":" << setw(2) << chosen_date.second << " ) " << endl;
}

int Time_managment::from_gregorian_to_julian(const Date& date) {
	if (date < Date({8, 3, 1300, 0, 0, 0})) return 7;
	if (Date({ 7, 3, 1300, 0, 0, 0 }) < date && date < Date({ 9, 3, 1400, 0, 0, 0 })) return 8;
	if (Date({ 8, 3, 1400, 0, 0, 0 }) < date && date < Date({ 10, 3, 1500, 0, 0, 0 })) return 9;
	if (Date({ 9, 3, 1500, 0, 0, 0 }) < date && date < Date({ 11, 3, 1700, 0, 0, 0 })) return 10;
	if (Date({ 10, 3, 1700, 0, 0, 0 }) < date && date < Date({ 12, 3, 1800, 0, 0, 0 })) return 11;
	if (Date({ 11, 3, 1800, 0, 0, 0 }) < date && date < Date({ 13, 3, 1900, 0, 0, 0 })) return 12;
	if (Date({ 12, 3, 1900, 0, 0, 0 }) < date && date < Date({ 14, 3, 2100, 0, 0, 0 })) return 13;
	if (Date({ 13, 3, 2100, 0, 0, 0 }) < date) return 14;
}