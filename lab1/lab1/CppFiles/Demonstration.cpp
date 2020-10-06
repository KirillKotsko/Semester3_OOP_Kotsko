#include "../HeaderFiles/Demonstration/Demonstration.h"

using namespace std;

template <typename T>
ostream& operator<<(ostream& os, const vector<T>& a) {
	for (const auto& x : a) {
		os << x << " ";
	}
	return os;
}

void demonstration_stack() {
	system("cls");
	cout << "Demontstration functionality stack with int: " << endl << endl;
	Sleep(2000);
	Stack<int> test;
	cout << "Create (Stack<int> test). " << endl;
	Sleep(700);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;
	int a = rand();
	cout << "int a = " << a << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(1000);
	test.push(a);
	cout << "Let's push int a: test.push(a). " << endl;
	Sleep(1000);
	cout << "Check value: " << endl;
	Sleep(1000);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(2000);
	cout << "Let's push something else: int b. " << endl;
	int b = rand();
	Sleep(1000);
	cout << "int b = " << b << endl;
	test.push(b);
	cout << "Let's push int b: test.push(b). " << endl;
	Sleep(500);
	cout << "Check value: " << endl;
	Sleep(2000);
	cout << "test.peek() = " << test.peek() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop them. " << endl;
	Sleep(1000);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(1000);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(2000);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void demonstraation_queue() {
	system("cls");
	cout << "Demontstration functionality queue with string: " << endl << endl;
	Sleep(2000);
	Queue<string> test(10);
	cout << "Create (Queue<string> test(10)). " << endl;
	Sleep(700);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	string a = "abc";
	cout << "string a = " << a << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(1000);
	test.push(a);
	cout << "Let's push string a: test.push(a). " << endl;
	Sleep(1000);
	cout << "Check value: " << endl;
	Sleep(1000);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(2000);
	cout << "Let's push something else: string b. " << endl;
	string b = "simple";
	Sleep(1000);
	cout << "string b = " << b << endl;
	test.push(b);
	cout << "Let's push string b: test.push(b). " << endl;
	Sleep(500);
	cout << "Check value: " << endl;
	Sleep(2000);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop. " << endl;
	Sleep(1000);
	cout << "test.pop() = " << test.pop() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(1000);
	cout << "test.pop() = " << test.pop() << endl;
	Sleep(2000);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void demonstration_deque() {
	system("cls");
	cout << "Demontstration functionality deque with vector<int>: " << endl << endl;
	Sleep(2000);
	Deque<vector<int> > test(15);
	cout << "Create (Deque<vector<int>> test(15)). " << endl;
	Sleep(700);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	vector<int> a = { 1,2,3 };

	cout << "vector<int> a = " << a << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(1000);
	test.push_back(a);
	cout << "Let's push_back vector<int> a: test.push_back(a). " << endl;
	Sleep(1000);
	cout << "Check value: " << endl;
	Sleep(1000);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(2000);
	cout << "Let's push_front something else: vector<int> b. " << endl;
	vector<int> b = { 7,8,9 };
	Sleep(1000);
	cout << "vector<int> b = " << b << endl;
	test.push_front(b);
	cout << "Let's push vector<int> b: test.push_front(b). " << endl;
	Sleep(500);
	cout << "Check value: " << endl;
	Sleep(2000);
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop front. " << endl;
	Sleep(1000);
	cout << "test.pop_front() = " << test.pop_front() << endl;
	cout << "test.front() = " << test.front() << endl;
	cout << "test.back() = " << test.back() << endl;
	Sleep(1000);
	cout << "Let's pop back. " << endl;
	cout << "test.pop_back() = " << test.pop_back() << endl;
	Sleep(2000);
	cout << "Check empty of deque: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

int menu()
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

void demonstration_mode_stack() {
	system("cls");
	cout << "Demontstration functionality stack with Time_managment: " << endl << endl;
	Sleep(2000);
	Stack<Time_managment> test;
	cout << "Create (Stack<Time_managment> test). " << endl;
	Sleep(700);
	cout << "Show max size of stack: test.max_size() = " << test.max_size() << endl;
	Time_managment a;
	cout << "Time_managment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(1000);
	test.push(a);
	cout << "Let's push Time_managment a: test.push(a). " << endl;
	Sleep(1000);
	cout << "Check value: " << endl;
	Sleep(1000);
	Time_managment b = test.peek();
	cout << " Time_managment b = test.peek(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop. " << endl;
	Sleep(1000);
	b = test.pop();
	cout << " b = test.pop(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(2000);
	cout << "Check empty of stack: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void demonstration_mode_queue() {
	system("cls");
	cout << "Demontstration functionality queue with Time_managment: " << endl << endl;
	Sleep(2000);
	Queue<Time_managment> test(10);
	cout << "Create (Queue<Time_managment> test(10)). " << endl;
	Sleep(700);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;
	Time_managment a;
	cout << "Time_managment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(1000);
	test.push(a);
	cout << "Let's push Time_managment a: test.push(a). " << endl;
	Sleep(1000);
	cout << "Check value: " << endl;
	Sleep(1000);
	Time_managment b = test.front();
	cout << "Time_managment b = test.front(), b.get_date1 = " << b.get_date(1) << endl;
	b = test.back();
	cout << "b = test.back(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop. " << endl;
	Sleep(1000);
	b = test.pop();
	cout << "b = test.pop(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(2000);
	cout << "Check empty of queue: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}

void demonstration_mode_deque() {
	system("cls");
	cout << "Demontstration functionality deque with Time_managment: " << endl << endl;
	Sleep(2000);
	Deque<Time_managment> test(15);
	cout << "Create (Deque<Time_managment> test(15)). " << endl;
	Sleep(700);
	cout << "Show max size of queue: test.max_size() = " << test.max_size() << endl;

	Time_managment a;
	cout << "Time_managment a. a.get_date(1) = " << a.get_date(1) << endl;
	Sleep(500);
	cout << "test.empty() = " << test.empty() << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	cout << "Let's push_front Time_managment a. test.push_front(a)" << endl;
	test.push_front(a);
	Sleep(500);
	cout << "Check value: " << endl;
	Sleep(2000);
	Time_managment b = test.front();
	cout << "Time_managment b = test.front(), b.get_date(1) = " << b.get_date(1) << endl;
	b = test.back();
	cout << "b = test.back(), b.get_date(1) = " << b.get_date(1) << endl;
	cout << "test.size() = " << test.size() << endl << endl;
	Sleep(3000);
	cout << "Let's pop back. " << endl;
	b = test.pop_back();
	cout << "b = test.pop_back(), b.get_date(1) = " << b.get_date(1) << endl;
	Sleep(2000);
	cout << "Check empty of deque: test.empty() = " << test.empty() << endl << endl;
	Sleep(2000);

	cout << "End of demonstration. " << endl << endl;
	system("pause");
	system("cls");
}