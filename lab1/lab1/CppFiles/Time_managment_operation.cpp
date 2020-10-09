/**
*   @file Time_managment_operation.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/

#include "../HeaderFiles/Date/Date.h"

using namespace std;

DifferenceBetweenDate TimeManagment::minus_for_dates(Date date1_, Date date2_) {
	DifferenceBetweenDate result;

	// Ammount days of each month.
	int mounth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };
	// Variable which is used for calculate days difference.
	int sum = 0;
	if (date2_ < date1_) swap(date1_, date2_);
	
	// Variant for equal years.
	if (date1_.year == date2_.year && date1_.month != date2_.month)
	{
		if ((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) mounth[1]++;
		sum += date2_.day + (mounth[date1_.month - 1] - date1_.day);
		for (int i = date1_.month; i < date2_.month - 1; i++) sum += mounth[i];
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// Variant for equal years and month.
	else if (date1_.year == date2_.year && date1_.month == date2_.month && date1_.day != date2_.day) {
		sum = date2_.day - date1_.day;
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// Variant for equal years, month and days.
	else if (date1_.year == date2_.year && date1_.month == date2_.month && date1_.day == date2_.day) {
		int seconds = (date2_.hour - date1_.hour) * 3600 + (date2_.minute - date1_.minute) * 60 + date2_.second - date1_.second;
		result.hour = (seconds / 3600);
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	// All others cases.
	else {
		int mounth_ammount_day_year1 = 0;
		for (int i = 0; i < date1_.month - 1; i++)
		{
			mounth_ammount_day_year1 += mounth[i];
			if (((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) && i == 1) mounth_ammount_day_year1++;
		}
		sum += 365 - (date1_.day + mounth_ammount_day_year1);
		if ((date1_.year % 4 == 0 && date1_.year % 100 != 0) || (date1_.year % 400 == 0)) sum++;
		int mounth_ammount_day_year2 = 0;
		for (int i = 0; i < date2_.month - 1; i++)
		{
			mounth_ammount_day_year2 += mounth[i];
			if (((date2_.year % 4 == 0 && date2_.year % 100 != 0) || (date2_.year % 400 == 0)) && i == 1) mounth_ammount_day_year2++;
		}
		sum += date2_.day + mounth_ammount_day_year2;
		int years_ammount_day = 0;
		for (int i = date1_.year + 1; i < date2_.year; i++)
		{
			years_ammount_day += 365;
			if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0)) years_ammount_day++;
		}
		sum += years_ammount_day;
		sum--;
		int seconds = date2_.hour * 3600 + date2_.minute * 60 + date2_.second + (86400 - (date1_.hour * 3600 + date1_.minute * 60 + date1_.second));
		if (seconds / 3600 >= 24) {
			result.hour = (seconds / 3600) - 24;
			sum++;
		}
		else {
			result.hour = (seconds / 3600);
		}
		result.minute = (seconds % 3600) / 60;
		result.seconds = (seconds % 3600) % 60;
	}
	result.days = sum;
	return result;
}

Date TimeManagment::date_plus_diff(Date date, DifferenceBetweenDate plus) {
	Date result = { date.day, date.month, date.year, 0, 0, 0 };

	int days = plus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = date.hour * 3600 + date.minute * 60 + date.second + plus.hour * 3600 + plus.minute * 60 + plus.seconds;
	if (seconds / 3600 >= 24) {
		hour_to_record = (seconds / 3600) - 24;
		days++;
	}
	else hour_to_record = seconds / 3600;
	minute_to_record = (seconds % 3600) / 60;
	seconds_to_record = (seconds % 3600) % 60;
	while (days != 0) {
		Date to_compare = { 1, result.month % 12 + 1, result.year, 0, 0, 0 };
		if (to_compare.month == 1) to_compare.year++;
		DifferenceBetweenDate remainder = minus_for_dates(to_compare, result);
		if (remainder.days <= days) {
			result = to_compare;
			days -= remainder.days;
		}
		else {
			result.day += days;
			days = 0;
		}
	}
	result.hour = hour_to_record;
	result.minute = minute_to_record;
	result.second = seconds_to_record;
	return result;
}

Date TimeManagment::date_minus_diff(Date date, DifferenceBetweenDate minus) {
	Date result = { date.day, date.month, date.year, 0, 0, 0 };

	// Ammount days of each month.
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 , 31 };

	int days = minus.days;
	int hour_to_record, minute_to_record, seconds_to_record;
	int seconds = 86400 + (date.hour * 3600 + date.minute * 60 + date.second) - (minus.hour * 3600 + minus.minute * 60 + minus.seconds);
	if (seconds < 86400) {
		hour_to_record = (seconds / 3600);
		days++;
	}
	else {
		seconds -= 86400;
		hour_to_record = (seconds / 3600);
	}
	minute_to_record = (seconds % 3600) / 60;
	seconds_to_record = (seconds % 3600) % 60;
	while (days != 0) {
		if ((result.year % 4 == 0 && result.year % 100 != 0) || (result.year % 400 == 0)) month[1] = 29;
		else month[1] = 28;
		Date to_compare = { 1, (result.month + 11) % 12, result.year, 0, 0, 0 };
		if (to_compare.month == 0) {
			to_compare.month = 12;
			to_compare.year--;
		}
		to_compare.day = month[to_compare.month - 1];
		DifferenceBetweenDate remainder = minus_for_dates(result, to_compare);
		if (remainder.days <= days) {
			result = to_compare;
			days -= remainder.days;
		}
		else {
			result.day -= days;
			days = 0;
		}
	}
	result.hour = hour_to_record;
	result.minute = minute_to_record;
	result.second = seconds_to_record;
	return result;
}

