/**
*	@file UI.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include "../Containers/ContainersLink.h"
#include "../Work with date/WorkWithDate.h"
#include "windows.h"
#include <cstdlib>
#include <vector>

using namespace std;

/**
* @brief User Interface
*
* The class consist method which are create UI.
*/
class UI {
public:

	/**
	 * Overload for vector which used for demonstration function.
	 * @param stream.
	 * @param vector thats outputs.
	 * @tparam T Type of data that used in vector.
	 * @return stream.
	 */
	template <typename T>
	friend ostream& operator<<(ostream& os, const vector<T>& a);

	/**
	 * Main menu interface.
	 * @return choice of user.
	 */
	int main_menu();
	/**
	 * Menu of menu item "Demonstration mode".
	 * @return choice of user.
	 */
	int demonstration_choice_menu();
	/**
	 * Menu which helps user choice variant of date difference output.
	 * @return choice of user.
	 */
	int variant_of_output_difference();

	/**
	* Four methods that demonstrate the functionality of the stack using
	* int, string, vector<int> and custom class TimeManagment.
	*/
	void demonstration_mode_stack_int();
	void demonstration_mode_stack_string();
	void demonstration_mode_stack_vector();
	void demonstration_mode_stack_custom();

	/**
	* Four methods that demonstrate the functionality of the queue using
	* int, string, vector<int> and custom class TimeManagment.
	*/
	void demonstration_mode_queue_int();
	void demonstration_mode_queue_string();
	void demonstration_mode_queue_vector();
	void demonstration_mode_queue_custom();

	/**
	* Four methods that demonstrate the functionality of the deque using
	* int, string, vector<int> and custom class TimeManagment.
	*/
	void demonstration_mode_deque_int();
	void demonstration_mode_deque_string();
	void demonstration_mode_deque_vector();
	void demonstration_mode_deque_custom();
};

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
	for (const auto& x : a) {
		os << x << " ";
	}
	return os;
}
