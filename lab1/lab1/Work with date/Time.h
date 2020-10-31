/**
*	@file Time.h
*	@author Kirill Kotsko
*	@version 1.2
*/
#pragma once

#include <iostream>

using namespace std;

/**
* @brief Time
*
* The class represents the Time.
*/
class Time {
public:

	// Ammount of hours.
	int hour;
	// Ammount of minutes.
	int minute;
	// Ammount of seconds.
	int second;

	// Default constructor. Initializes Time variabels.
	Time() : hour(0), minute(0), second(0) {}

	/**
	* @brief constructor
	*
	* @param value of hour
	* @param value of minute
	* @param value of seconds
	*/
	Time(int hour_, int minute_, int second_) : hour(hour_), minute(minute_), second(second_) {}
};