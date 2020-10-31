/**
*	@file TimeMangment.h
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
#include "DifferenceBetweenDateWithTime.h"
#include "TimeIsNow.h"

using namespace std;

/**
* @brief Users time managment
*
* The class that helps user with time managment.
* Performs operations on the current DateWithTime and two user-specified ones.
*/
class TimeManagment : public TimeIsNow {
public:

	// Default constructor. Initializes variable date_with_time1 and.
	TimeManagment();
	/**
	* @brief constructor
	*
	* @param first date_with_time.
	* @param second date_with_time.
	*/
	TimeManagment(const DateWithTime& a, const DateWithTime& b);
	// Destructor.
	~TimeManagment();

	/**
	* Method get difference between date_with_time1 and date_with_time2.
	*
	* @return difference between date_with_times.
	*/
	DifferenceBetweenDateWithTime get_difference();
	/**
	* Method for calculating difference between two date_with_times (replacement operation "-").
	*
	* @param first date_with_time.
	* @param second date_with_time.
	* @return result.
	*/
	DifferenceBetweenDateWithTime minus_for_date_with_times(DateWithTime date_with_time1_, DateWithTime date_with_time2_);
	/**
	* Method for calculating date_with_time plus difference which you want to add (replacement operation "+").
	*
	* @param date_with_time.
	* @param difference which you want to add.
	* @return new date_with_time (new date_with_time - date_with_time = difference).
	*/
	DateWithTime date_with_time_plus_diff(DateWithTime date_with_time, DifferenceBetweenDateWithTime plus);
	/**
	* Method for calculating date_with_time minus difference which you want to substract (replacement operation "-").
	*
	* @param date_with_time.
	* @param difference which you want to substract.
	* @return new date_with_time (date_with_time - new date_with_time = difference).
	*/
	DateWithTime date_with_time_minus_diff(DateWithTime date_with_time, DifferenceBetweenDateWithTime minus);
	/**
	* Method for user. Show difference between date_with_time1 and date_with_time2 which the user asked.
	* @param mode for output.
	*/
	void show_difference(int mode);
	/**
	* Method which add difference to current date_with_time or date_with_time1 or date_with_time2, which the user asked.
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @param difference to add.
	* @return result date_with_time.
	*/
	DateWithTime add_difference(int num_of_date_with_time, DifferenceBetweenDateWithTime to_add);
	/**
	* Method which substract difference to current date_with_time or date_with_time1 or date_with_time2, which the user asked.
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @param difference to substract.
	* @return result date_with_time.
	*/
	DateWithTime substract_difference(int num_of_date_with_time, DifferenceBetweenDateWithTime to_substract);

	/**
	* Method check: date_with_time exist or not.
	*
	* @param 1 - date_with_time1, 2 - date_with_time2
	* @return true or false.
	*/
	bool check_date_with_time(int num_of_date_with_time);
	/**
	* Method set the date_with_time1 or date_with_time2. Checks existent of date_with_time with help of "check_date_with_time" method.
	*
	* @param 1 - date_with_time1, 2 - date_with_time2
	*/
	void set_date_with_time(const DateWithTime& a, int num_of_date_with_time);

	/**
	* Get the date_with_time from class TimeManagment.
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @return date_with_time.
	*/
	DateWithTime get_date_with_time(int num_of_date_with_time);
	/**
	* Show the date_with_time from class TimeManagment.
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	*/
	void show_date_with_time(int num_of_date_with_time);

	/**
	* Function that calculate ammount of days that we need to substract.
	*
	* @param date_with_time.
	* @return ammount of days.
	*/
	int from_gregorian_to_julian(const DateWithTime& date_with_time);
	/**
	* Show current date_with_time, date_with_time1, date_with_time2 in julian calendar.
	*/
	void show_julian_calendar();

	/**
	* Method calculate number of weekday by date_with_time
	*
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @return num of weekday.
	*/
	int get_weekday_of_date_with_time(int num_of_date_with_time);
	/**
	* Method calculate num week of the date_with_time in month.
	*
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @return num of week.
	*/
	int week_in_month(int num_of_date_with_time);
	/**
	* Method calculate num week of the date_with_time in year.
	*
	* @param 0 - current date_with_time, 1 - date_with_time1, 2 - date_with_time2.
	* @return num of week.
	*/
	int week_in_year(int num_of_date_with_time);
	/**
	* Show day of the week of current date_with_time, date_with_time1, date_with_time2.
	*/
	void day_of_the_week();
	/**
	* Show alternative variant of date_with_time represent.
	*/
	void alternative_insert_of_date_with_time(int num_of_date_with_time);

	/**
	* Overload of operator "=" for class TimeManagment.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	TimeManagment& operator=(TimeManagment right);

private:
	// First date_with_time which is set by the user.
	DateWithTime date_with_time1;
	// Second date_with_time which is set by the user.
	DateWithTime date_with_time2;

	// Constant that names the week days.
	const string WEEK_DAY[7] = { "Saturday" , "Sunday" , "Monday" , "Tuesday" ,
							 "Wednesday" , "Thursday" , "Friday" };
	// Constant that names month.
	const string MONTH_NAME[12] = { "January" , "Febuary" , "March" , "April" ,
									 "May" , "June" , "July", "August" , "September" ,
									 "October" , "November" ,  "December" };
	// Constant with special code for each month. Details: https://lifehacker.ru/kakoj-den-nedeli/.
	const int CODE_OF_MONTH[12] = { 1 , 4 , 4 , 0 , 2 , 5 , 0 , 3 , 6 , 1 , 4 , 6 };
	// Constant with special code for four type of years. Details: https://lifehacker.ru/kakoj-den-nedeli/.
	const int CODE_OF_YEAR[4] = { 6 , 4 , 2 , 0 };
	// Constant which represent ammount days of each month.
	const int DAY_IN_MONTH[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };
};
