/**
*	@file Date.h
*	@author Kirill Kotsko
*	@version 1.1
*/

#pragma once
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

/**
* @brief Difference between dates
*
* The class represents difference between two dates.
*/
class DifferenceBetweenDate {
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
	DifferenceBetweenDate() : days(0), hour(0), minute(0), seconds(0) {}
	/**
	* @brief constructor
	*
	* @param difference in days
	* @param difference in hours
	* @param difference in minutes
	* @param difference in seconds
	*/
	DifferenceBetweenDate(int day_, int hour_, int minute_, int second_) : days(day_), hour(hour_),
		minute(minute_), seconds(second_) {}

	/**
	* Overload of operator "=" for class DifferenceBetweenDate.
	* @param Variable to copy data.
	* @return Changed variable.
	*/
	DifferenceBetweenDate& operator=(const DifferenceBetweenDate& right);
	/**
	* Method that change variable "variant_of_output".
	* @param Choice mode by user.
	*/
	void change_variant_of_output(int choice);
	/**
	* Overload of operator "==" for class Date.
	* @param Left hand side param for operator.
	* @param Right hand side param for operator.
	* @return True or false.
	*/
	friend bool operator==(const DifferenceBetweenDate& lhs, const DifferenceBetweenDate& rhs);
	/**
	 * Overload of operator "<<" for date.
	 * @param stream.
	 * @param date thats outputs.
	 * @return stream.
	 */
	friend ostream& operator<<(ostream& os, const DifferenceBetweenDate& date);
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


