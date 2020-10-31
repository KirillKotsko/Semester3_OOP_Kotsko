/**
*	@file TimeIsNow.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iomanip>
#include "DateWithTime.h"

using namespace std;

/**
* @brief Current time
*
* The class represents methods for work with current DateWithTime.
*/
class TimeIsNow {
public:
	// Default constructor. Initializes variable by current DateWithTime.
	TimeIsNow();
	// Destructor.
	~TimeIsNow();

	/**
	* Method for user. Changes time zone.
	*/
	void change_GMT();
	/**
	* Output current DateWithTime.
	*/
	void show_current_date_with_time();
	/**
	* Method that get current date_with_time.
	* @return current date_with_time
	*/
	DateWithTime get_current_date_with_time();

private:

	/**
	* Method that controlled up-to-date of the date.
	*/
	void update();

	// Current date_with_time
	DateWithTime current_date_with_time;
	// Time zone behind which the current date_with_time is determined.
	int GMT;
};
