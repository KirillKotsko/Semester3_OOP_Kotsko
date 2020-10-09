#include "../HeaderFiles/Date/Date.h"

using namespace std;

TimeManagment::TimeManagment() {
	date1 = get_current_date();
	date2 = get_current_date();
}

TimeManagment::TimeManagment(const Date& a, const Date& b) {
	set_date(a, 1);
	set_date(b, 2);
}

TimeManagment::~TimeManagment() {}

bool TimeManagment::check_date(int num_of_date) {
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

void TimeManagment::set_date(const Date& a, int num_of_date) {
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

Date TimeManagment::get_date(int num_of_date) {
	if (num_of_date == 1) return date1;
	else return date2;
}

void TimeManagment::show_date(int num_of_date) {
	if (num_of_date == 1) cout << "Date1: " << date1 << endl;
	else cout << "Date2: " << date2 << endl;
}

int TimeManagment::get_weekday_of_date(int num_of_date) {
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

void TimeManagment::day_of_the_week() {
	show_current_date();
	cout << "Current date day of the week: " << WEEK_DAY[get_weekday_of_date(0)] << endl;
	show_date(1);
	cout << "Date1 day of the week: " << WEEK_DAY[get_weekday_of_date(1)] << endl;
	show_date(2);
	cout << "Date2 day of the week: " << WEEK_DAY[get_weekday_of_date(2)] << endl;
}

DifferenceBetweenDate TimeManagment::get_difference() {
	return minus_for_dates(date1, date2);
}

Date TimeManagment::add_difference(int num_of_date, DifferenceBetweenDate to_add) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return date_plus_diff(chosen_date, to_add);
}

Date TimeManagment::substract_difference(int num_of_date, DifferenceBetweenDate to_substract) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	return date_minus_diff(chosen_date, to_substract);
}

void TimeManagment::show_difference(int mode) {
	DifferenceBetweenDate to_print = get_difference();
	to_print.change_variant_of_output(mode);
	cout << to_print << endl;
}

void TimeManagment::show_julian_calendar() {
	DifferenceBetweenDate transfer_days_to_julian = DifferenceBetweenDate({ from_gregorian_to_julian(get_current_date()), 0, 0, 0 });
	cout << "Current date in Julian calendar: " << date_minus_diff(get_current_date(), transfer_days_to_julian) << endl;
	transfer_days_to_julian = DifferenceBetweenDate({ from_gregorian_to_julian(date1), 0, 0, 0 });
	cout << "Date1 in Julian calendar: " << date_minus_diff(date1, transfer_days_to_julian) << endl;
	transfer_days_to_julian = DifferenceBetweenDate({ from_gregorian_to_julian(date2), 0, 0, 0 });
	cout << "Date2 in Julian calendar: " << date_minus_diff(date2, transfer_days_to_julian) << endl;
}

int TimeManagment::week_in_month(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	DifferenceBetweenDate tmp = minus_for_dates(chosen_date, Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 }));
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

int TimeManagment::week_in_year(int num_of_date) {
	Date chosen_date;
	if (num_of_date == 0) chosen_date = get_current_date();
	else if (num_of_date == 1) chosen_date = date1;
	else chosen_date = date2;

	DifferenceBetweenDate tmp = minus_for_dates(chosen_date, Date({ 1, 1, chosen_date.year, 0, 0, 0 }));
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

void TimeManagment::alternative_insert_of_date(int num_of_date) {
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
	DifferenceBetweenDate tmp = minus_for_dates(chosen_date, Date({ 1, chosen_date.month, chosen_date.year, 0, 0, 0 }));
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

int TimeManagment::from_gregorian_to_julian(const Date& date) {
	if (date < Date({ 8, 3, 1300, 0, 0, 0 })) return 7;
	if (Date({ 7, 3, 1300, 0, 0, 0 }) < date && date < Date({ 9, 3, 1400, 0, 0, 0 })) return 8;
	if (Date({ 8, 3, 1400, 0, 0, 0 }) < date && date < Date({ 10, 3, 1500, 0, 0, 0 })) return 9;
	if (Date({ 9, 3, 1500, 0, 0, 0 }) < date && date < Date({ 11, 3, 1700, 0, 0, 0 })) return 10;
	if (Date({ 10, 3, 1700, 0, 0, 0 }) < date && date < Date({ 12, 3, 1800, 0, 0, 0 })) return 11;
	if (Date({ 11, 3, 1800, 0, 0, 0 }) < date && date < Date({ 13, 3, 1900, 0, 0, 0 })) return 12;
	if (Date({ 12, 3, 1900, 0, 0, 0 }) < date && date < Date({ 14, 3, 2100, 0, 0, 0 })) return 13;
	if (Date({ 13, 3, 2100, 0, 0, 0 }) < date) return 14;
}

