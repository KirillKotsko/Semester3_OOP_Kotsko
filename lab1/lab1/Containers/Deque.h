/**
*	@file Deque.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include "Containers.h"
#include "Stack.h"
#include "Queue.h"
#include "IDeque.h"

using namespace std;

/**
* @brief Class Deque (double-ended queue)
*
* Represent all neccessary methods.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Deque : public IDeque<T>, public Stack<T>, public Queue<T> {
public:

	// Constructor
	Deque(int a = 30) : Container<T>(a) {}

	void push_front(const T&) override;
protected:
	// Storage of data
	Container<T>::data;
	// Current size of container
	Container<T>::current_size;
	// Maximal size of container
	Container<T>::maxsize;
};

template <typename T>
void Deque<T>::push_front(const T& value)
{
	if (current_size == maxsize) throw exception("Container is full!!!");
	for (int i = current_size; i > 0; i--) data[i] = data[i - 1];
	current_size++;
	data[0] = value;
}