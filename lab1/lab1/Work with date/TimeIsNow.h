#pragma once
/**
*	@file TimeIsNow.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <cstdio>
#include <conio.h>
#include <vector>
#include <iomanip>
#include "Date.h"

using namespace std; 

/**
* @brief Current time
*
* The class represents methods for work with current date.
*/
class TimeIsNow {
public:
	// Default constructor. Initializes variable by current date.
	TimeIsNow();
	// Destructor.
	~TimeIsNow();

	/**
	* Method for user. Changes time zone.
	*/
	void change_GMT();
	/**
	* Output current date.
	*/
	void show_current_date();
	/**
	* Method that get current date.
	* @return current date
	*/
	Date get_current_date();

private:

	/**
	* Method that controlled up-to-date of the date.
	*/
	void update();

	// Current date
	Date current_date;
	// Time zone behind which the current date is determined.
	int GMT;
};