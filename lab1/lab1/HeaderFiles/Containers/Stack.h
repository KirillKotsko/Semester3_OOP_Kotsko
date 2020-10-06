#pragma once
#include <iostream>
#include <exception>
#include "Deque.h"

using namespace std;

template <typename T>
class Stack {
public:
	Stack(int a = 30) : stack(Deque<T>(a)) {}

	T pop() { return stack.pop_back(); };
	const T& peek() { return stack.back(); };
	void push(const T& value) { stack.push_back(value); };
	bool empty() { return stack.empty(); };
	int max_size() const { return stack.max_size(); };
	int size() const { return stack.size(); };
private:
	Deque<T> stack;
};