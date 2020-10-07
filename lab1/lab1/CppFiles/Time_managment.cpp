#include "../HeaderFiles/Date/Date.h"

using namespace std;

Difference_between_date operator-(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;
	if (date2 < date1) swap(date1, date2);

	if (date1.year == date2.year && date1.month != date2.month)
	{
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
	}
	else if (date1.year == date2.year && date1.month == date2.month && date1.day != date2.day) {
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
	}
	else if (date1.year == date2.year && date1.month == date2.month && date1.day == date2.day) {
		int seconds = (date2.hour - date1.hour) * 3600 + (date2.minute - date1.minute) * 60 + date2.second - date1.second;
		result.hour = (seconds / 3600);
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	else {
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
	}
	result.days = sum;
	return result;
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
	return date1 - date2;
}

Date Time_managment::add_difference(int num_of_date, Difference_between_date to_add) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return chosen_date + to_add;
}

Date Time_managment::substract_difference(int num_of_date, Difference_between_date to_substract) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return chosen_date - to_substract;
}

void Time_managment::show_difference() {
	cout << get_difference() << endl;
}

void Time_managment::show_julian_calendar() {
	Difference_between_date transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(get_current_date()), 0, 0, 0 });
	cout << "Current date in Julian calendar: " << get_current_date() - transfer_days_to_julian << endl;
	transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(date1), 0, 0, 0 });
	cout << "Date1 in Julian calendar: " << date1 - transfer_days_to_julian << endl;
	transfer_days_to_julian = Difference_between_date({ from_gregorian_to_julian(date2), 0, 0, 0 });
	cout << "Date2 in Julian calendar: " << date2 - transfer_days_to_julian << endl;
}

int Time_managment::week_in_month(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	Difference_between_date tmp = chosen_date - Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 });
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

	Difference_between_date tmp = chosen_date - Date({ 1, 1, chosen_date.year, 0, 0, 0 });
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
	Difference_between_date tmp = chosen_date - Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 });
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