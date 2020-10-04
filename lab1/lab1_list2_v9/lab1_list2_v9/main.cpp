#include "date.h"
#include "unit_test_framework.h"
#include "test.h"
#include "demonstration.h"

using namespace std;

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestDateMinusDate);
	RUN_TEST(tr, TestDateAddDifference);
	RUN_TEST(tr, TestDateMinusDifference);
	RUN_TEST(tr, TestWeekDay);
	RUN_TEST(tr, TestWeekInMonth);
	RUN_TEST(tr, TestWeekInYear);
	RUN_TEST(tr, TestTimeManagmentInContainers);
	system("pause");

	bool work = true;
	Time_managment x;
	while (work) {
		switch (menu())
		{
		case 0: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			system("pause");
			break;
		}
		case 1: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			cout << "Insert date1. Example: 12.12.2012 12:0:0 " << endl;
			cout << "Insert: ";
			Date date;
			cin >> date;
			x.set_date(date, 1);
			system("pause");
			break;
		}
		case 2: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			cout << "Insert date2. Example: 12.12.2012 12:0:0 " << endl;
			cout << "Insert: ";
			Date date;
			cin >> date;
			x.set_date(date, 2);
			system("pause");
			break;
		}
		case 3: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			x.alternative_insert_of_date(0);
			x.alternative_insert_of_date(1);
			x.alternative_insert_of_date(2);
			system("pause");
			break;
		}
		case 4: {
			x.change_GMT();
			cout << "Successfully changed! " << endl;
			system("pause");
			break;
		}
		case 5: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			x.show_difference();
			cout << endl;
			cout << "Current day + this difference " << x.add_difference(0, x.get_difference()) << endl;
			cout << "Current day - this difference " << x.substract_difference(0, x.get_difference()) << endl;
			cout << endl;
			cout << "Date1 + this difference " << x.add_difference(1, x.get_difference()) << endl;
			cout << "Date1 - this difference " << x.substract_difference(1, x.get_difference()) << endl;
			cout << endl;
			cout << "Date2 + this difference " << x.add_difference(2, x.get_difference()) << endl;
			cout << "Date2 - this difference " << x.substract_difference(2, x.get_difference()) << endl;
			system("pause");
			break;
		}
		case 6: {
			x.day_of_the_week();
			system("pause");
			break;
		}
		case 7: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			cout << "Current date - number of week in this month is " << x.week_in_month(0) << " and in this year " << x.week_in_year(0) << endl;
			cout << "Date1 - number of week in this month is " << x.week_in_month(1) << " and in this year " << x.week_in_year(1) << endl;
			cout << "Date2 - number of week in this month is " << x.week_in_month(2) << " and in this year " << x.week_in_year(2) << endl;
			system("pause");
			break;
		}
		case 8: {
			x.show_current_date();
			x.show_date(1);
			x.show_date(2);
			cout << endl;

			x.show_julian_calendar();
			system("pause");
			break;
		}
		case 9: {
			demonstration_mode_stack();
			demonstration_mode_queue();
			demonstration_mode_deque();

			break;
		}
		case 10: {
			work = false;
			break;
		}
		}
	}
	return 0;
}