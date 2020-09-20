#include "Header.h"

using namespace std;

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

Difference_between_date operator-(Date date1, Date date2) {
	Difference_between_date result;

	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	int sum = 0;
	if ((date1.year > date2.year) || (date1.year == date2.year && date1.month > date2.month) ||
		(date1.year == date2.year && date1.month == date2.month && date1.day > date2.day) ||
		(date1.year == date2.year && date1.month == date2.month && date1.day == date2.day && (date1.hour * 3600 + date1.minute * 60 + date1.second > date2.hour * 3600 + date2.minute * 60 + date2.second)))
		swap(date1, date2);

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

Time_is_now::Time_is_now() {
	GMT = 3;
	update();
}

Time_is_now::~Time_is_now() {}

void Time_is_now::update() {
	time_t seconds = time(NULL);
	seconds += 3600 * (-3) + GMT * 3600;
	tm* timeinfo = localtime(&seconds);
	current_date.day = timeinfo->tm_mday;
	current_date.month = timeinfo->tm_mon + 1;
	current_date.year = timeinfo->tm_year + 1900;
	current_date.hour = timeinfo->tm_hour;
	current_date.minute = timeinfo->tm_min;
	current_date.second = timeinfo->tm_sec;
}

void Time_is_now::change_GMT() {
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "Choose GMT: ";
		cout << endl;
		key = (key + 24) % 24;
		if (key == 0) cout << "-> GMT-11" << endl;
		else  cout << "   GMT-11" << endl;
		if (key == 1) cout << "-> GMT-10" << endl;
		else  cout << "   GMT-10" << endl;
		if (key == 2) cout << "-> GMT-9" << endl;
		else  cout << "   GMT-9" << endl;
		if (key == 3) cout << "-> GMT-8" << endl;
		else  cout << "   GMT-8" << endl;
		if (key == 4) cout << "-> GMT-7" << endl;
		else  cout << "   GMT-7" << endl;
		if (key == 5) cout << "-> GMT-6" << endl;
		else  cout << "   GMT-6" << endl;
		if (key == 6) cout << "-> GMT-5" << endl;
		else  cout << "   GMT-5" << endl;
		if (key == 7) cout << "-> GMT-4" << endl;
		else  cout << "   GMT-4" << endl;
		if (key == 8) cout << "-> GMT-3" << endl;
		else  cout << "   GMT-3" << endl;
		if (key == 9) cout << "-> GMT-2" << endl;
		else  cout << "   GMT-2" << endl;
		if (key == 10) cout << "-> GMT-1" << endl;
		else  cout << "   GMT-1" << endl;
		if (key == 11) cout << "-> GMT+0" << endl;
		else  cout << "   GMT+0" << endl;
		if (key == 12) cout << "-> GMT+1" << endl;
		else  cout << "   GMT+1" << endl;
		if (key == 13) cout << "-> GMT+2" << endl;
		else  cout << "   GMT+2" << endl;
		if (key == 14) cout << "-> GMT+3" << endl;
		else  cout << "   GMT+3" << endl;
		if (key == 15) cout << "-> GMT+4" << endl;
		else  cout << "   GMT+4" << endl;
		if (key == 16) cout << "-> GMT+5" << endl;
		else  cout << "   GMT+5" << endl;
		if (key == 17) cout << "-> GMT+6" << endl;
		else  cout << "   GMT+6" << endl;
		if (key == 18) cout << "-> GMT+7" << endl;
		else  cout << "   GMT+7" << endl;
		if (key == 19) cout << "-> GMT+8" << endl;
		else  cout << "   GMT+8" << endl;
		if (key == 20) cout << "-> GMT+9" << endl;
		else  cout << "   GMT+9" << endl;
		if (key == 21) cout << "-> GMT+10" << endl;
		else  cout << "   GMT+10" << endl;
		if (key == 22) cout << "-> GMT+11" << endl;
		else  cout << "   GMT+11" << endl;
		if (key == 23) cout << "-> GMT+12" << endl;
		else  cout << "   GMT+12" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	key -= 11;
	GMT = key;
}

void Time_is_now::show_current_date() {
	update();
	cout << "Today is " << current_date << "GMT";
	if (GMT >= 0) cout << "+";
	cout << GMT << endl;
}

Date Time_is_now::get_current_date() {
	update();
	return current_date;
}

Time_managment::Time_managment() {
	date1 = get_current_date();
	date2 = get_current_date();
}

Time_managment::Time_managment(const Date& a, const Date& b) {
	set_date(a,1);
	set_date(b,2);
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
	if (num_of_date == 1) chosen_date = date1;
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
	show_date(1);
	cout << "Date1 day of the week: " << WEEK_DAY[get_weekday_of_date(1)] << endl;
	show_date(2);
	cout << "Date2 day of the week: " << WEEK_DAY[get_weekday_of_date(2)] << endl;
}

Difference_between_date Time_managment::get_difference() {
	return date1 - date2;
}

void Time_managment::show_difference() {
	cout << get_difference() << endl;
}

