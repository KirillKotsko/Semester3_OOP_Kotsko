#include "test.h"

void TestDateMinusDate() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 543, 18, 22, 26 }));
	test.set_date(Date({ 10, 8, 2020, 14, 55, 32 }), 2);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 4, 0, 0, 0 }));
	test.set_date(Date({ 2, 3, 2019, 20, 33, 6 }), 1);
	test.set_date(Date({ 9, 2, 2019, 20, 33, 6 }), 2);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 21, 0, 0, 0 }));
	test.set_date(Date({ 9, 2, 2019, 5, 12, 59 }), 1);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 0, 15, 20, 7 }));
	test.set_date(Date({ 9, 2, 2020, 20, 33, 7 }), 1);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 365, 0, 0, 1 }));
	test.set_date(Date({ 9, 2, 2021, 20, 33, 7 }), 2);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 366, 0, 0, 0 }));
	test.set_date(Date({ 19, 6, 1950, 19, 0, 0 }), 1);
	test.set_date(Date({ 05, 03, 2012, 21, 0, 0 }), 2);
	ASSERT_EQUAL(test.get_difference(), Difference_between_date({ 22540, 2, 0, 0 }));

}

void TestDateAddDifference() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.add_difference(2, test.get_difference()), Date({ 6, 8, 2020, 14, 55, 32 }));
	test.set_date(Date({ 19, 6, 1950, 19, 0, 0 }), 1);
	test.set_date(Date({ 05, 03, 2012, 21, 0, 0 }), 2);
	ASSERT_EQUAL(test.add_difference(1, test.get_difference()), Date({ 05, 03, 2012, 21, 0, 0 }));
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 1);
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 2);
	ASSERT_EQUAL(test.add_difference(1, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 0 }));
	ASSERT_EQUAL(test.add_difference(2, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 0 }));
	test.set_date(Date({ 01, 01, 2001, 21, 0, 1 }), 2);
	ASSERT_EQUAL(test.add_difference(1, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 1 }));
	ASSERT_EQUAL(test.add_difference(2, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 2 }));

}

void TestDateMinusDifference() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.substract_difference(1, test.get_difference()), Date({ 9, 2, 2019, 20, 33, 6 }));
	test.set_date(Date({ 19, 6, 1950, 19, 0, 0 }), 1);
	test.set_date(Date({ 05, 03, 2012, 21, 0, 0 }), 2);
	ASSERT_EQUAL(test.substract_difference(2, test.get_difference()), Date({ 19, 6, 1950, 19, 0, 0 }));
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 1);
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 2);
	ASSERT_EQUAL(test.substract_difference(1, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 0 }));
	ASSERT_EQUAL(test.substract_difference(2, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 0 }));
	test.set_date(Date({ 01, 01, 2001, 21, 0, 1 }), 2);
	ASSERT_EQUAL(test.substract_difference(1, test.get_difference()), Date({ 01, 01, 2001, 20, 59, 59 }));
	ASSERT_EQUAL(test.substract_difference(2, test.get_difference()), Date({ 01, 01, 2001, 21, 0, 0 }));
}

void TestWeekDay() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.get_weekday_of_date(1), 5); //Thursday
	ASSERT_EQUAL(test.get_weekday_of_date(2), 0); //Saturday
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 1);
	test.set_date(Date({ 21, 6, 1950, 19, 0, 0 }), 2);
	ASSERT_EQUAL(test.get_weekday_of_date(1), 2); //Monday
	ASSERT_EQUAL(test.get_weekday_of_date(2), 4); //Wednesday
	test.set_date(Date({ 24, 02, 2015, 0, 0, 0 }), 1);
	test.set_date(Date({ 17, 04, 2020, 0, 0, 0 }), 2);
	ASSERT_EQUAL(test.get_weekday_of_date(1), 3); //Tuesday
	ASSERT_EQUAL(test.get_weekday_of_date(2), 6); //Friday
	test.set_date(Date({ 31, 05, 2020, 0, 0, 0 }), 1);
	ASSERT_EQUAL(test.get_weekday_of_date(1), 1); //Sunday
}

void TestWeekInMonth() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.week_in_month(1), 2); 
	ASSERT_EQUAL(test.week_in_month(2), 2); 
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 1);
	test.set_date(Date({ 21, 6, 1950, 19, 0, 0 }), 2);
	ASSERT_EQUAL(test.week_in_month(1), 1);
	ASSERT_EQUAL(test.week_in_month(2), 4);
	test.set_date(Date({ 24, 02, 2015, 0, 0, 0 }), 1);
	test.set_date(Date({ 17, 04, 2020, 0, 0, 0 }), 2);
	ASSERT_EQUAL(test.week_in_month(1), 5); 
	ASSERT_EQUAL(test.week_in_month(2), 3); 
	test.set_date(Date({ 31, 05, 2020, 0, 0, 0 }), 1);
	ASSERT_EQUAL(test.week_in_month(1), 5);
}

void TestWeekInYear() {
	Time_managment test({ 6, 8, 2020, 14, 55, 32 }, { 9, 2, 2019, 20, 33, 6 });
	ASSERT_EQUAL(test.week_in_year(1), 32);
	ASSERT_EQUAL(test.week_in_year(2), 6);
	test.set_date(Date({ 01, 01, 2001, 21, 0, 0 }), 1);
	test.set_date(Date({ 21, 6, 1950, 19, 0, 0 }), 2);
	ASSERT_EQUAL(test.week_in_year(1), 1);
	ASSERT_EQUAL(test.week_in_year(2), 26);
	test.set_date(Date({ 24, 02, 2015, 0, 0, 0 }), 1);
	test.set_date(Date({ 17, 04, 2020, 0, 0, 0 }), 2);
	ASSERT_EQUAL(test.week_in_year(1), 9);
	ASSERT_EQUAL(test.week_in_year(2), 16);
	test.set_date(Date({ 31, 05, 2020, 0, 0, 0 }), 1);
	ASSERT_EQUAL(test.week_in_year(1), 22);
}

