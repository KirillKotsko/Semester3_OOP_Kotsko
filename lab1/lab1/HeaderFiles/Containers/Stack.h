/**
*	@file Stack.h
*	@author Kirill Kotsko
*	@version 1.1
*/

#pragma once
#include <iostream>
#include <exception>
#include "Deque.h"

using namespace std;

/**
* @brief Class Stack
*
* Represent all neccessary methods. Composition of the deque class.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Stack {
public:
	// Constructor
	Stack(int a = 30) : stack(Deque<T>(a)) {}

	T pop() { return stack.pop_back(); };
	const T& peek() { return stack.back(); };
	void push(const T& value) { stack.push_back(value); };
	bool empty() { return stack.empty(); };
	int max_size() const { return stack.max_size(); };
	int size() const { return stack.size(); };
private:
	// Storage of data
	Deque<T> stack;
};