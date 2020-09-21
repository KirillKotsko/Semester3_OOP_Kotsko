#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iomanip>

using namespace std;

const string WEEK_DAY[7] = { "Saturday" , "Sunday" , "Monday" , "Tuesday" , 
                             "Wednesday" , "Thursday" , "Friday" };
const string MONTH_NAME[12] = { "January" , "Febuary" , "March" , "April" , 
                                 "May" , "June" , "July", "August" , "September" , 
	                             "October" , "November" ,  "December" };
const int CODE_OF_MONTH[12] = { 1 , 4 , 4 , 0 , 2 , 5 , 0 , 3 , 6 , 1 , 4 , 6 };
const int CODE_OF_YEAR[4] = { 6 , 4 , 2 , 0 };
const int DAY_IN_MONTH[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };


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

int menu();
int from_gregorian_to_julian(const Date& date);

istream& operator>>(istream& stream, Date& date);
ostream& operator<<(ostream& os, const Date& date);
ostream& operator<<(ostream& os, const Difference_between_date& date);
bool operator<(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
Date operator+(Date date, Difference_between_date plus);
Date operator-(Date date, Difference_between_date minus);
Difference_between_date operator-(Date date1, Date date2);