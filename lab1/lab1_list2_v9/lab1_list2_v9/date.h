#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iomanip>

using namespace std;

struct Date {
	int day;
	int month;
	int year;
	int hour;
	int minute;
	int second;
};

struct Difference_between_date {
	int days;
	int hour;
	int minute;
	int seconds;
};

class Time_is_now {
public:
	Time_is_now();
	~Time_is_now();

	void change_GMT();
	void show_current_date();
	Date get_current_date();
private:
	void update();
	Date current_date;
	int GMT;
};

class Time_managment : public Time_is_now {
public:
	Time_managment();
	Time_managment(const Date& a, const Date& b);
	~Time_managment();

	Difference_between_date get_difference();
	void show_difference();
	bool check_date(int num_of_date);
	void set_date(const Date& a, int num_of_date);
	Date add_difference(int num_of_date, Difference_between_date to_add);
	Date substract_difference(int num_of_date, Difference_between_date to_substract);
	Date get_date(int num_of_date);
	void show_date(int num_of_date);
	void show_julian_calendar();
	int get_weekday_of_date(int num_of_date);
	int week_in_month(int num_of_date);
	int week_in_year(int num_of_date);
	void day_of_the_week();
	void alternative_insert_of_date(int num_of_date);

private:
	Date date1;
	Date date2;
};
