#pragma once
/**
*	@file Date.h
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

using namespace std;

/**
* @brief Date
*
* The class represents the date.
*/
class Date {
public:

	// Number of day.
	int day;
	// Number of month.
	int month;
	// Number of year.
	int year;
	// Ammount of hours.
	int hour;
	// Ammount of minutes.
	int minute;
	// Ammount of seconds.
	int second;

	// Default constructor. Initializes date variabels.
	Date() : day(0), month(0), year(0),
		hour(0), minute(0), second(0) {}

	/**
	* @brief constructor
	*
	* @param value of day
	* @param value of month
	* @param value of year
	* @param value of hour
	* @param value of minute
	* @param value of seconds
	*/
	Date(int day_, int month_, int year_, int hour_, int minute_, int second_) : day(day_), month(month_), year(year_),
		hour(hour_), minute(minute_), second(second_) {}


	/**
	* Overload of operator "=" for class Date.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	Date& operator=(const Date& right);
	/**
	* Overload of operator "<" for class Date.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator<(const Date& lhs, const Date& rhs);
	/**
	* Overload of operator ">" for class Date.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator>(const Date& lhs, const Date& rhs);
	/**
	* Overload of operator "==" for class Date.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator==(const Date& lhs, const Date& rhs);
	/**
	 * Overload of operator ">>" for date.
	 * @param stream.
	 * @param date thats inputs.
	 * @return stream.
	 */
	friend istream& operator>>(istream& stream, Date& date);
	/**
	 * Overload of operator "<<" for date.
	 * @param stream.
	 * @param date thats outputs.
	 * @return stream.
	 */
	friend ostream& operator<<(ostream& os, const Date& date);
};
