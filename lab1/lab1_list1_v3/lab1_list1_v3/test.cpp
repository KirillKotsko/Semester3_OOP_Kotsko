#include "test.h"

void TestStack() {
	{
		Stack<string> test(10);
		ASSERT_EQUAL(test.max_size(), 10);
		string text = "first elem";
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		test.push(text);
		ASSERT_EQUAL(test.peek(), text);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.empty(), 0);
		string from_pop = test.pop();
		ASSERT_EQUAL(from_pop, text);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		test.push("1");
		test.push("2");
		test.push("3");
		test.push("4");
		ASSERT_EQUAL(test.peek(), "4");
		ASSERT_EQUAL(test.size(), 4);
		ASSERT_EQUAL(test.pop(), "4");
		ASSERT_EQUAL(test.size(), 3);
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.peek(), "3");
		string garbage1 = test.pop();
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.size(), 2);
		ASSERT_EQUAL(garbage1, "3");
		ASSERT_EQUAL(test.peek(), "2");
		garbage1 = test.pop();
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(garbage1, "2");
		ASSERT_EQUAL(test.peek(), "1");
		garbage1 = test.pop();
		ASSERT_EQUAL(test.empty(), 1);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(garbage1, "1");
	}
	{
		Stack<int> test;
		ASSERT_EQUAL(test.max_size(), 30);
		ASSERT_EQUAL(test.empty(), 1);
		int a = 50;
		test.push(a);
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.peek(), a);
		ASSERT_EQUAL(test.size(), 1);
		int b = test.pop();
		ASSERT_EQUAL(b, 50);
		ASSERT_EQUAL(b, a);
		ASSERT_EQUAL(test.empty(), 1);
		ASSERT_EQUAL(test.size(), 0);
	}
}

void TestQueue() {
	{
		Queue<string> test(5);
		ASSERT_EQUAL(test.max_size(), 5);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		string a, b, c;
		a = "a";
		b = "b";
		c = "c";
		test.push(a);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.front(), test.back());
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.empty(), 0);
		test.push(b);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.back(), b);
		ASSERT_EQUAL(test.size(), 2);
		test.push(c);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.back(), c);
		ASSERT_EQUAL(test.size(), 3);
		ASSERT_EQUAL(test.pop(), a);
		ASSERT_EQUAL(test.front(), b);
		ASSERT_EQUAL(test.back(), c);
		ASSERT_EQUAL(test.size(), 2);
		ASSERT_EQUAL(test.pop(), b);
		ASSERT_EQUAL(test.front(), c);
		ASSERT_EQUAL(test.back(), test.front());
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.pop(), c);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
	}
	{
		Queue<int> test;
		ASSERT_EQUAL(test.max_size(), 30);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		int a = 6;
		int b = 10;
		test.push(a);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.front(), 6);
		ASSERT_EQUAL(test.front(), test.back());
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.empty(), 0);
		test.push(b);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.front(), 6);
		ASSERT_EQUAL(b, test.back());
		ASSERT_EQUAL(10, test.back());
		ASSERT_EQUAL(test.size(), 2);
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.pop(), 6);
		ASSERT_EQUAL(test.pop(), 10);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
	}
}

void TestDeque() {
	{
		Deque<string> test(10);
		ASSERT_EQUAL(test.max_size(), 10);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		string a, b, c, d, e;
		a = "a";
		b = "b";
		c = "c";
		d = "d";
		e = "e";
		test.push_back(c);
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.back(), "c");
		ASSERT_EQUAL(test.front(), test.back());
		test.push_front(b);
		ASSERT_EQUAL(test.back(), c);
		ASSERT_EQUAL(test.front(), b);
		test.push_back(d);
		ASSERT_EQUAL(test.back(), d);
		ASSERT_EQUAL(test.front(), b);
		test.push_back(e);
		ASSERT_EQUAL(test.back(), e);
		ASSERT_EQUAL(test.front(), b);
		test.push_front(a);
		ASSERT_EQUAL(test.back(), e);
		ASSERT_EQUAL(test.front(), a);
		ASSERT_EQUAL(test.size(), 5);
		ASSERT_EQUAL(test.pop_front(), a);
		ASSERT_EQUAL(test.size(), 4);
		ASSERT_EQUAL(test.back(), e);
		ASSERT_EQUAL(test.front(), b);
		ASSERT_EQUAL(test.pop_front(), b);
		ASSERT_EQUAL(test.size(), 3);
		ASSERT_EQUAL(test.back(), e);
		ASSERT_EQUAL(test.front(), c);
		ASSERT_EQUAL(test.pop_back(), e);
		ASSERT_EQUAL(test.size(), 2);
		ASSERT_EQUAL(test.back(), d);
		ASSERT_EQUAL(test.front(), c);
		ASSERT_EQUAL(test.pop_back(), d);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.back(), c);
		ASSERT_EQUAL(test.front(), test.back());
		ASSERT_EQUAL(test.pop_back(), c);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
	}
	{
		Deque<double> test(10);
		ASSERT_EQUAL(test.max_size(), 10);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
		test.push_back(3);
		ASSERT_EQUAL(test.empty(), 0);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.back(), 3);
		ASSERT_EQUAL(test.front(), test.back());
		test.push_front(2);
		ASSERT_EQUAL(test.back(), 3);
		ASSERT_EQUAL(test.front(), 2);
		test.push_back(4);
		ASSERT_EQUAL(test.back(), 4);
		ASSERT_EQUAL(test.front(), 2);
		test.push_back(5);
		ASSERT_EQUAL(test.back(), 5);
		ASSERT_EQUAL(test.front(), 2);
		test.push_front(1);
		ASSERT_EQUAL(test.back(), 5);
		ASSERT_EQUAL(test.front(), 1);
		ASSERT_EQUAL(test.size(), 5);
		ASSERT_EQUAL(test.pop_front(), 1);
		ASSERT_EQUAL(test.size(), 4);
		ASSERT_EQUAL(test.back(), 5);
		ASSERT_EQUAL(test.front(), 2);
		ASSERT_EQUAL(test.pop_front(), 2);
		ASSERT_EQUAL(test.size(), 3);
		ASSERT_EQUAL(test.back(), 5);
		ASSERT_EQUAL(test.front(), 3);
		ASSERT_EQUAL(test.pop_back(), 5);
		ASSERT_EQUAL(test.size(), 2);
		ASSERT_EQUAL(test.back(), 4);
		ASSERT_EQUAL(test.front(), 3);
		ASSERT_EQUAL(test.pop_back(), 4);
		ASSERT_EQUAL(test.size(), 1);
		ASSERT_EQUAL(test.back(), 3);
		ASSERT_EQUAL(test.front(), test.back());
		ASSERT_EQUAL(test.pop_back(), 3);
		ASSERT_EQUAL(test.size(), 0);
		ASSERT_EQUAL(test.empty(), 1);
	}
}
