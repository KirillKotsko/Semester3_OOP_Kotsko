#include "../HeaderFiles/Demonstration/Demonstration.h"

using namespace std;

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
	cout << "Demontstration functionality queue with Time_managment: " << endl << endl;
	Sleep(200);
	Queue<Time_managment> test(10);
	cout << "Create (Queue<Time_managment> test(10)). " << endl;
	Sleep(200);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	
	Time_managment a;
	cout << "Time_managment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(200);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(200);
	test.push(a);
	cout << "Let's push Time_managment a: test.push(a). " << endl;
	Sleep(200);
	cout << "Check value: " << endl;
	Sleep(200);
	Time_managment b = test.front();
	cout << "Time_managment b = test.front(), b.get_date1 = " << b.get_date(1) << endl;
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