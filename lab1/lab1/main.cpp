/**
*	@file main.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/

#include "../lab1/Containers/ContainersLink.h"
#include "../lab1/Work with date/DateWithTime.h"
#include "../lab1/UserInterface/UI.h"

using namespace std;

/**
 * @brief Main function of program
 *
 * UI that will help the user to use the functionality of the program.
 */

int main() {
	// Variable that signals the end of the user's work with the program
	bool work = true;
	// Variable with which the user will be used while using the program.
	TimeManagment x;
	// Variable which controlled by user.
	UI user;
	while (work) {
		/**
		* Represents the functionality of each menu item
		* @param Choice of the user
		*/
		switch (user.main_menu())
		{
		case 0: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			system("pause");
			break;
		}
		case 1: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			cout << "Insert date_with_time1. Example: 12.12.2012 12:00:00 " << endl;
			cout << "Insert: ";
			DateWithTime date_with_time;
			try {
				cin >> date_with_time;
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
			}
			if (cin.fail()) {
				cin.clear();
				cin.ignore(INT_MAX, '\n');
			}
			x.set_date_with_time(date_with_time, 1);
			system("pause");
			break;
		}
		case 2: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			cout << "Insert date_with_time2. Example: 12.12.2012 12:00:00 " << endl;
			cout << "Insert: ";
			DateWithTime date_with_time;
			try {
				cin >> date_with_time;
			}
			catch (exception& ex) {
				cout << ex.what() << endl;
			}
			x.set_date_with_time(date_with_time, 2);
			system("pause");
			break;
		}
		case 3: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			x.alternative_insert_of_date_with_time(0);
			x.alternative_insert_of_date_with_time(1);
			x.alternative_insert_of_date_with_time(2);
			system("pause");
			break;
		}
		case 4: {
			x.change_GMT();
			x.show_current_date_with_time();
			cout << "Successfully changed! " << endl;
			system("pause");
			break;
		}
		case 5: {
			/**
			* Variable that shows with what parameters
			* the user wants to see the difference between date_with_times.
			*/
			int choice = user.variant_of_output_difference();

			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			x.show_difference(choice);
			cout << endl;
			cout << "Current day + this difference " << x.add_difference(0, x.get_difference()) << endl;
			cout << "Current day - this difference " << x.substract_difference(0, x.get_difference()) << endl;
			cout << endl;
			cout << "Date_with_time1 + this difference " << x.add_difference(1, x.get_difference()) << endl;
			cout << "Date_with_time1 - this difference " << x.substract_difference(1, x.get_difference()) << endl;
			cout << endl;
			cout << "Date_with_time2 + this difference " << x.add_difference(2, x.get_difference()) << endl;
			cout << "Date_with_time2 - this difference " << x.substract_difference(2, x.get_difference()) << endl;
			system("pause");
			break;
		}
		case 6: {
			x.day_of_the_week();
			system("pause");
			break;
		}
		case 7: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			cout << "Current date_with_time - number of week in this month is " << x.week_in_month(0) << " and in this year " << x.week_in_year(0) << endl;
			cout << "Date_with_time1 - number of week in this month is " << x.week_in_month(1) << " and in this year " << x.week_in_year(1) << endl;
			cout << "Date_with_time2 - number of week in this month is " << x.week_in_month(2) << " and in this year " << x.week_in_year(2) << endl;
			system("pause");
			break;
		}
		case 8: {
			x.show_current_date_with_time();
			x.show_date_with_time(1);
			x.show_date_with_time(2);
			cout << endl;

			x.show_julian_calendar();
			system("pause");
			break;
		}
		case 9: {
			// Variable that signals the end of the user's work with the menu item.
			bool work_of_component = true;
			while (work_of_component) {
				/**
				* Represents the functionality of demonstration mode.
				* @param Choice of the user
				*/
				switch (user.demonstration_choice_menu())
				{
				case 0: {
					user.demonstration_mode_stack_int();
					user.demonstration_mode_queue_int();
					user.demonstration_mode_deque_int();
					break;
				}
				case 1: {
					user.demonstration_mode_stack_string();
					user.demonstration_mode_queue_string();
					user.demonstration_mode_deque_string();
					break;
				}
				case 2: {
					user.demonstration_mode_stack_vector();
					user.demonstration_mode_queue_vector();
					user.demonstration_mode_deque_vector();
					break;
				}
				case 3: {
					user.demonstration_mode_stack_custom();
					user.demonstration_mode_queue_custom();
					user.demonstration_mode_deque_custom();
					break;
				}
				case 4: {
					work_of_component = false;
					break;
				}
				}
			}
			break;
		}
		case 10: {
			// End of user's work with program.
			work = false;
			break;
		}
		}
	}
	return 0;
}
