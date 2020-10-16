/**
*	@file Stack.h
*	@author Kirill Kotsko
*	@version 1.2
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

	/**
	* Remove top element
	*
	* @return This element
	*/
	T pop() { return stack.pop_back(); };

	/**
	* Access top element
	*
	* @return This element
	*/
	const T& peek() { return stack.back(); };

	/**
	* Add element at the end
	*/
	void push(const T& value) { stack.push_back(value); };

	/**
	* Test whether container is empty
	*
	* @return true ore false
	*/
	bool empty() { return stack.empty(); };

	/**
	* Return maximum size of container
	*
	* @return max size
	*/
	int max_size() const { return stack.max_size(); };
	
	/**
	* Return current size of container
	*
	* @return size
	*/
	int size() const { return stack.size(); };
private:
	// Storage of data
	Deque<T> stack;
}; 