/**
*	@file DateWithTime.h
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
#include "Date.h"
#include "Time.h"

using namespace std;

/**
* @brief DateWithTime
*
* The class represents the DateWithTime.
*/
class DateWithTime : public Date, public Time {
public:

	// Default constructor. Initializes DateWithTime variabels.
	DateWithTime() : Date(),
		Time() {}

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
	DateWithTime(int day_, int month_, int year_, int hour_, int minute_, int second_) : Date(day_, month_, year_),
		Time(hour_, minute_, second_) {}


	/**
	* Overload of operator "=" for class DateWithTime.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	DateWithTime& operator=(const DateWithTime& right);
	/**
	* Overload of operator "<" for class DateWithTime.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator<(const DateWithTime& lhs, const DateWithTime& rhs);
	/**
	* Overload of operator ">" for class DateWithTime.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator>(const DateWithTime& lhs, const DateWithTime& rhs);
	/**
	* Overload of operator "==" for class DateWithTime.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator==(const DateWithTime& lhs, const DateWithTime& rhs);
	/**
	 * Overload of operator ">>" for DateWithTime.
	 * @param stream.
	 * @param DateWithTime thats inputs.
	 * @return stream.
	 */
	friend istream& operator>>(istream& stream, DateWithTime& DateWithTime_);
	/**
	 * Overload of operator "<<" for DateWithTime.
	 * @param stream.
	 * @param DateWithTime thats outputs.
	 * @return stream.
	 */
	friend ostream& operator<<(ostream& os, const DateWithTime& DateWithTime_);
};

