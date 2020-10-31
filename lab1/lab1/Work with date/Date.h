/**
*	@file Date.h
*	@author Kirill Kotsko
*	@version 1.2
*/
#pragma once

#include <iostream>

using namespace std;

/**
* @brief Date
*
* The class represents the Date.
*/
class Date {
public:

	// Number of day.
	int day;
	// Number of month.
	int month;
	// Number of year.
	int year;

	// Default constructor. Initializes Date variabels.
	Date() : day(0), month(0), year(0) {}

	/**
	* @brief constructor
	*
	* @param value of day
	* @param value of month
	* @param value of year
	*/
	Date(int day_, int month_, int year_) : day(day_), month(month_), year(year_) {}
};