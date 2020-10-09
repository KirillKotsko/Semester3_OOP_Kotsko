#pragma once
#include "../Containers/Containers.h"
#include "../Date/Date.h"
#include "windows.h"
#include <cstdlib>
#include <vector>

using namespace std;

class UI {
public:
	template <typename T>
	friend ostream& operator<<(ostream& os, const vector<T>& a);
	
	int main_menu();
	int demonstration_choice_menu();
	int variant_of_output_difference();

	void demonstration_mode_stack_int();
	void demonstration_mode_stack_string();
	void demonstration_mode_stack_vector();
	void demonstration_mode_stack_custom();

	void demonstration_mode_queue_int();
	void demonstration_mode_queue_string();
	void demonstration_mode_queue_vector();
	void demonstration_mode_queue_custom();
	
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