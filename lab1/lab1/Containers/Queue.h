/**
*	@file Queue.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>
#include "Deque.h"

using namespace std;

/**
* @brief Class Queue
*
* Represent all neccessary methods. Composition of the deque class.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Queue {
public:
	// Constructor
	Queue(int a = 30) : queue(Deque<T>(a)) {}

	/**
	* Add element at the end
	*/
	void push(const T& value) { queue.push_back(value); };

	/**
	* Test whether container is empty
	*
	* @return true ore false
	*/
	bool empty() { return queue.empty(); };

	/**
	* Return maximum size of container
	*
	* @return max size
	*/
	int max_size() const { return queue.max_size(); };

	/**
	* Return current size of container
	*
	* @return size
	*/
	int size() const { return queue.size(); };

	/**
	* Remove first element
	*
	* @return This element
	*/
	T pop() { return queue.pop_front(); };

	/**
	* Access first element
	*
	* @return This element
	*/
	const T& front() { return queue.front(); };

	/**
	* Access top element
	*
	* @return This element
	*/
	const T& back() { return queue.back(); };

private:
	// Storage of data
	Deque<T> queue;
};
