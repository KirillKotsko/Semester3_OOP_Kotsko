#include "../HeaderFiles/Demonstration/Demonstration.h"

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
