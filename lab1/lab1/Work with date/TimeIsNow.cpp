/**
*	@file TimeIsNow.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../Work with date/TimeIsNow.h"

using namespace std;

TimeIsNow::TimeIsNow() {
	GMT = 2;
	update();
}

TimeIsNow::~TimeIsNow() {}

void TimeIsNow::update() {
	time_t seconds = time(NULL);
	seconds += 3600 * (-2) + GMT * 3600;
	tm* timeinfo = localtime(&seconds);
	current_date_with_time.day = timeinfo->tm_mday;
	current_date_with_time.month = timeinfo->tm_mon + 1;
	current_date_with_time.year = timeinfo->tm_year + 1900;
	current_date_with_time.hour = timeinfo->tm_hour;
	current_date_with_time.minute = timeinfo->tm_min;
	current_date_with_time.second = timeinfo->tm_sec;
}

void TimeIsNow::change_GMT() {
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

void TimeIsNow::show_current_date_with_time() {
	update();
	cout << "Today is " << current_date_with_time << "GMT";
	if (GMT >= 0) cout << "+";
	cout << GMT << endl;
}

DateWithTime TimeIsNow::get_current_date_with_time() {
	update();
	return current_date_with_time;
}
