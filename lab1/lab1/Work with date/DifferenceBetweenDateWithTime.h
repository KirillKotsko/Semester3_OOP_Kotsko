#pragma once
/**
*	@file DifferenceBetweenDateWithTime.h
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
* @brief Difference between dates
*
* The class represents difference between two dates.
*/
class DifferenceBetweenDateWithTime {
public:

	// Variable that shows difference in days.
	int days;
	// Variable that shows difference in hours.
	int hour;
	// Variable that shows difference in minutes.
	int minute;
	// Variable that shows difference in secnods.
	int seconds;

	// Default constructor. Initializes variables by 0.
	DifferenceBetweenDateWithTime() : days(0), hour(0), minute(0), seconds(0) {}
	/**
	* @brief constructor
	*
	* @param difference in days
	* @param difference in hours
	* @param difference in minutes
	* @param difference in seconds
	*/
	DifferenceBetweenDateWithTime(int day_, int hour_, int minute_, int second_) : days(day_), hour(hour_),
		minute(minute_), seconds(second_) {}

	/**
	* Overload of operator "=" for class DifferenceBetweenDateWithTime.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	DifferenceBetweenDateWithTime& operator=(const DifferenceBetweenDateWithTime& right);
	/**
	* Method that change variable "variant_of_output".
	* @param Choice mode by user.
	*/
	void change_variant_of_output(int choice);
	/**
	* Overload of operator "==" for class DifferenceBetweenDateWithTime.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator==(const DifferenceBetweenDateWithTime& lhs, const DifferenceBetweenDateWithTime& rhs);
	/**
	 * Overload of operator "<<" for DifferenceBetweenDateWithTime.
	 * @param stream.
	 * @param DifferenceBetweenDateWithTime thats outputs.
	 * @return stream.
	 */
	friend ostream& operator<<(ostream& os, const DifferenceBetweenDateWithTime& DateWithTime_);
private:

	/**
	* Variable for user. Value of the mode that displays
	* the difference for the given parameters.
	*
	* Default (0) - DHMS (days, hours, minutes and seconds).
	* (1) - HMS (hours, minutes and seconds).
	* (2) - MS (minutes and seconds).
	* (3) - S (seconds).
	*/
	int variant_of_output = 0;
};
