/**
*	@file UI.cpp
*	@author Kirill Kotsko
*	@version 1.2
*/

#include "../UserInterface/UI.h"

using namespace std;

void UI::demonstration_mode_deque_int() {
	system("cls");
	cout << "Demontstration functionality deque with int: " << endl << endl;
	Sleep(200);
	Deque<int> test(20);
	cout << "Create (Deque<int> test(20)). " << endl;
	Sleep(200);
	cout << "Show max size of deque: test.max_size() = " << test.max_size() << endl;


	int a = rand();
	cout << "int a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push_back int a: test.push(a). " << endl;
	test.push_back(a);
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push_front something else: int b. " << endl;
	int b = rand();
	Sleep(200);
	cout << "int b = " << b << endl;
	test.push_back(b);
	cout << "Let's push_front int b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop them. " << endl;
	Sleep(200);
	cout << "test.pop_front() = " << test.pop_front() << endl;
	Sleep(200);
	cout << "test.pop_back() = " << test.pop_back() << endl;
	Sleep(200);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_deque_string() {
	system("cls");
	cout << "Demontstration functionality deque with string: " << endl << endl;
	Sleep(200);
	Deque<string> test(5);
	cout << "Create (Deque<string> test(5)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	string a = "abc";
	cout << "string a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);

	cout << "Let's push string a: test.push_back(a). " << endl;
	test.push_back(a);
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push_front something else: string b. " << endl;
	string b = "simple";
	Sleep(200);
	cout << "string b = " << b << endl;
	test.push_front(b);
	cout << "Let's push string b: test.push_front(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop them. " << endl;
	Sleep(200);
	cout << "test.pop_back() = " << test.pop_back() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(200);
	cout << "test.pop_front() = " << test.pop_front() << endl;
	Sleep(200);
	cout << "Check empty of deque: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_deque_vector() {
	system("cls");
	cout << "Demontstration functionality deque with vector<int>: " << endl << endl;
	Sleep(200);
	Deque<vector<int> > test(15);
	cout << "Create (Deque<vector<int>> test(15)). " << endl;
	Sleep(200);
	cout << "Show max size of deque: test.max_size() = " << test.max_size() << endl;
	vector<int> a = { 1,2,3 };

	cout << "vector<int> a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push_back(a);
	cout << "Let's push_back vector<int> a: test.push_back(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push_front something else: vector<int> b. " << endl;
	vector<int> b = { 7,8,9 };
	Sleep(200);
	cout << "vector<int> b = " << b << endl;
	test.push_front(b);
	cout << "Let's push vector<int> b: test.push_front(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop front. " << endl;
	Sleep(200);
	cout << "test.pop_front() = " << test.pop_front() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(200);
	cout << "Let's pop back. " << endl;
	cout << "test.pop_back() = " << test.pop_back() << endl;
	Sleep(200);
	cout << "Check empty of deque: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_deque_custom() {
	system("cls");
	cout << "Demontstration functionality deque with TimeManagment: " << endl << endl;
	Sleep(200);
	Deque<TimeManagment> test(15);
	cout << "Create (Deque<TimeManagment> test(15)). " << endl;
	Sleep(200);
	cout << "Show max size of deque: test.max_size() = " << test.max_size() << endl;

	TimeManagment a;
	cout << "TimeManagment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	cout << "Let's push_front TimeManagment a. test.push_front(a)" << endl;
	test.push_front(a);
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	TimeManagment b = test.front();
	cout << "TimeManagment b = test.front(), b.get_date(1) = " << b.get_date(1) << endl;
	b = test.back();
	cout << "b = test.back(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop back. " << endl;
	b = test.pop_back();
	cout << "b = test.pop_back(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(200);
	cout << "Check empty of deque: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_queue_int() {
	system("cls");
	cout << "Demontstration functionality queue with int: " << endl << endl;
	Sleep(200);
	Queue<int> test(20);
	cout << "Create (Queue<int> test(20)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;

	int a = rand();
	cout << "int a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push int a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push something else: int b. " << endl;
	int b = rand();
	Sleep(200);
	cout << "int b = " << b << endl;
	test.push(b);
	cout << "Let's push int b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop them. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_queue_string() {
	system("cls");
	cout << "Demontstration functionality queue with string: " << endl << endl;
	Sleep(200);
	Queue<string> test(10);
	cout << "Create (Queue<string> test(10)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;

	string a = "abc";
	cout << "string a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push string a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push something else: string b. " << endl;
	string b = "simple";
	Sleep(200);
	cout << "string b = " << b << endl;
	test.push(b);
	cout << "Let's push string b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_queue_vector() {
	system("cls");
	cout << "Demontstration functionality queue with vector<int>: " << endl << endl;
	Sleep(200);
	Queue<vector<int> > test(10);
	cout << "Create (Queue<vector<int>> test(10)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	vector<int> a = { 1,2,3 };

	cout << "vector<int> a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push vector<int> a: test.push_back(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push something else: vector<int> b. " << endl;
	vector<int> b = { 7,8,9 };
	Sleep(200);
	cout << "vector<int> b = " << b << endl;
	test.push(b);
	cout << "Let's push vector<int> b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(200);
	cout << "Let's pop back. " << endl;
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_queue_custom() {
	system("cls");
	cout << "Demontstration functionality queue with TimeManagment: " << endl << endl;
	Sleep(200);
	Queue<TimeManagment> test(10);
	cout << "Create (Queue<TimeManagment> test(10)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;

	TimeManagment a;
	cout << "TimeManagment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push TimeManagment a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	TimeManagment b = test.front();
	cout << "TimeManagment b = test.front(), b.get_date1 = " << b.get_date(1) << endl;
	b = test.back();
	cout << "b = test.back(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	b = test.pop();
	cout << "b = test.pop(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(200);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}


void UI::demonstration_mode_stack_int() {
	system("cls");
	cout << "Demontstration functionality stack with int: " << endl << endl;
	Sleep(200);
	Stack<int> test;
	cout << "Create (Stack<int> test). " << endl;
	Sleep(200);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;

	int a = rand();
	cout << "int a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push int a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push something else: int b. " << endl;
	int b = rand();
	Sleep(200);
	cout << "int b = " << b << endl;
	test.push(b);
	cout << "Let's push int b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop them. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_stack_string() {
	system("cls");
	cout << "Demontstration functionality stack with string: " << endl << endl;
	Sleep(200);
	Stack<string> test(10);
	cout << "Create (Stack<string> test(10)). " << endl;
	Sleep(200);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;

	string a = "abc";
	cout << "string a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push string a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push something else: string b. " << endl;
	string b = "simple";
	Sleep(200);
	cout << "string b = " << b << endl;
	test.push(b);
	cout << "Let's push string b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	cout << "test.peek() = " << test.peek() << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_stack_vector() {
	system("cls");
	cout << "Demontstration functionality stack with vector<int>: " << endl << endl;
	Sleep(200);
	Stack<vector<int> > test(15);
	cout << "Create (Stack<vector<int>> test(15)). " << endl;
	Sleep(200);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;
	vector<int> a = { 1,2,3 };

	cout << "vector<int> a = " << a << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push vector<int> a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's push_front something else: vector<int> b. " << endl;
	vector<int> b = { 7,8,9 };
	Sleep(200);
	cout << "vector<int> b = " << b << endl;
	test.push(b);
	cout << "Let's push vector<int> b: test.push(b). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	cout << "test.pop() = " << test.pop() << endl;
	cout << "test.peek() = " << test.peek() << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(200);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void UI::demonstration_mode_stack_custom() {
	system("cls");
	cout << "Demontstration functionality stack with TimeManagment: " << endl << endl;
	Sleep(200);
	Stack<TimeManagment> test;
	cout << "Create (Stack<TimeManagment> test). " << endl;
	Sleep(200);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;
	TimeManagment a;
	cout << "TimeManagment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push TimeManagment a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	TimeManagment b = test.peek();
	cout << " TimeManagment b = test.peek(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	cout << "Let's pop. " << endl;
	Sleep(200);
	b = test.pop();
	cout << " b = test.pop(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(200);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(200);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

int UI::main_menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#                          Menu                            #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 11) % 11;
		if (key == 0) cout << "-> Show dates" << endl;
		else  cout << "   Show dates" << endl;
		if (key == 1) cout << "-> Insert date1" << endl;
		else  cout << "   Insert date1" << endl;
		if (key == 2) cout << "-> Insert date2" << endl;
		else  cout << "   Insert date2" << endl;
		if (key == 3) cout << "-> Alternative date display" << endl;
		else  cout << "   Alternative date display" << endl;
		if (key == 4) cout << "-> Change of GMT" << endl;
		else  cout << "   Change of GMT" << endl;
		if (key == 5) cout << "-> Add and substract the difference of date1 and date2 to the dates" << endl;
		else  cout << "   Add and substract the difference of date1 and date2 to the dates" << endl;
		if (key == 6) cout << "-> Show day of week for each date" << endl;
		else  cout << "   Show day of week for each date" << endl;
		if (key == 7) cout << "-> Show week number in month and year for each date" << endl;
		else  cout << "   Show week number in month and year for each date" << endl;
		if (key == 8) cout << "-> Convert dates to Julian calendar" << endl;
		else  cout << "   Convert dates to Julian calendar" << endl;
		if (key == 9) cout << "-> Demontration mode with stack,queue,deque." << endl;
		else  cout << "   Demontration mode with stack,queue,deque." << endl;
		if (key == 10) cout << "-> Exit" << endl;
		else  cout << "   Exit" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int UI::demonstration_choice_menu() {
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#                 Show functionality using:                #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 5) % 5;
		if (key == 0) cout << "-> Int" << endl;
		else  cout << "   Int" << endl;
		if (key == 1) cout << "-> String" << endl;
		else  cout << "   String" << endl;
		if (key == 2) cout << "-> Vector<int>" << endl;
		else  cout << "   Vector<int>" << endl;
		if (key == 3) cout << "-> Custom class(TimeManagment)" << endl;
		else  cout << "   Custom class(TimeManagment)" << endl;
		if (key == 4) cout << "-> Back to main menu" << endl;
		else  cout << "   Back to main menu" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}

int UI::variant_of_output_difference() {
	int key = 0;
	int code;
	do {
		system("cls");
		cout << "############################################################" << endl;
		cout << "#     Choose variant of output difference between date     #" << endl;
		cout << "############################################################" << endl;
		cout << endl;
		key = (key + 4) % 4;
		if (key == 0) cout << "-> Standart (in days)" << endl;
		else  cout << "   Standart (in days)" << endl;
		if (key == 1) cout << "-> In hours" << endl;
		else  cout << "   In hours" << endl;
		if (key == 2) cout << "-> In minutes" << endl;
		else  cout << "   In minutes" << endl;
		if (key == 3) cout << "-> In seconds" << endl;
		else  cout << "   In seconds" << endl;

		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}
