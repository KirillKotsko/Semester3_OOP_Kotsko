#include "../HeaderFiles/Demonstration/Demonstration.h"

using namespace std;

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
