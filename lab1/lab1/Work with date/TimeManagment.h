#pragma once
/**
*	@file TimeMangment.h
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
#include "DifferenceBetweenDate.h"
#include "TimeIsNow.h"

using namespace std;

/**
* @brief Users time managment
*
* The class that helps user with time managment.
* Performs operations on the current date and two user-specified ones.
*/
class TimeManagment : public TimeIsNow {
public:

	// Default constructor. Initializes variable date1 and.
	TimeManagment();
	/**
	* @brief constructor
	*
	* @param first date.
	* @param second date.
	*/
	TimeManagment(const Date& a, const Date& b);
	// Destructor.
	~TimeManagment();

	/**
	* Method get difference between date1 and date2.
	*
	* @return difference between dates.
	*/
	DifferenceBetweenDate get_difference();
	/**
	* Method for calculating difference between two dates (replacement operation "-").
	*
	* @param first date.
	* @param second date.
	* @return result.
	*/
	DifferenceBetweenDate minus_for_dates(Date date1_, Date date2_);
	/**
	* Method for calculating date plus difference which you want to add (replacement operation "+").
	*
	* @param date.
	* @param difference which you want to add.
	* @return new date (new date - date = difference).
	*/
	Date date_plus_diff(Date date, DifferenceBetweenDate plus);
	/**
	* Method for calculating date minus difference which you want to substract (replacement operation "-").
	*
	* @param date.
	* @param difference which you want to substract.
	* @return new date (date - new date = difference).
	*/
	Date date_minus_diff(Date date, DifferenceBetweenDate minus);
	/**
	* Method for user. Show difference between date1 and date2 which the user asked.
	* @param mode for output.
	*/
	void show_difference(int mode);
	/**
	* Method which add difference to current date or date1 or date2, which the user asked.
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @param difference to add.
	* @return result date.
	*/
	Date add_difference(int num_of_date, DifferenceBetweenDate to_add);
	/**
	* Method which substract difference to current date or date1 or date2, which the user asked.
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @param difference to substract.
	* @return result date.
	*/
	Date substract_difference(int num_of_date, DifferenceBetweenDate to_substract);

	/**
	* Method check: date exist or not.
	*
	* @param 1 - date1, 2 - date2
	* @return true or false.
	*/
	bool check_date(int num_of_date);
	/**
	* Method set the date1 or date2. Checks existent of date with help of "check_date" method.
	*
	* @param 1 - date1, 2 - date2
	*/
	void set_date(const Date& a, int num_of_date);

	/**
	* Get the date from class TimeManagment.
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @return date.
	*/
	Date get_date(int num_of_date);
	/**
	* Show the date from class TimeManagment.
	* @param 0 - current date, 1 - date1, 2 - date2.
	*/
	void show_date(int num_of_date);

	/**
	* Function that calculate ammount of days that we need to substract.
	*
	* @param date.
	* @return ammount of days.
	*/
	int from_gregorian_to_julian(const Date& date);
	/**
	* Show current date, date1, date2 in julian calendar.
	*/
	void show_julian_calendar();

	/**
	* Method calculate number of weekday by date
	*
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @return num of weekday.
	*/
	int get_weekday_of_date(int num_of_date);
	/**
	* Method calculate num week of the date in month.
	*
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @return num of week.
	*/
	int week_in_month(int num_of_date);
	/**
	* Method calculate num week of the date in year.
	*
	* @param 0 - current date, 1 - date1, 2 - date2.
	* @return num of week.
	*/
	int week_in_year(int num_of_date);
	/**
	* Show day of the week of current date, date1, date2.
	*/
	void day_of_the_week();
	/**
	* Show alternative variant of date represent.
	*/
	void alternative_insert_of_date(int num_of_date);

	/**
	* Overload of operator "=" for class TimeManagment.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	TimeManagment& operator=(TimeManagment right);

private:
	// First date which is set by the user.
	Date date1;
	// Second date which is set by the user.
	Date date2;

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