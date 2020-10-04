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

