/**
*	@file Queue.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include "IQueue.h"
#include "Containers.h"

using namespace std;

/**
* @brief Class Queue
*
* Represent all neccessary methods. Composition of the deque class.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Queue : public IQueue<T>, virtual public Container<T> {
public:

	// Constructor
	Queue(int a = 30) : Container<T>(a) {}

	T pop_front() override;
	const T& front() override;
	const T& back() override;
protected:
	// Storage of data
	Container<T>::data;
	// Current size of container
	Container<T>::current_size;
	// Maximal size of container
	Container<T>::maxsize;
};

template <typename T>
const T& Queue<T>::front()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[0];
}

template <typename T>
const T& Queue<T>::back()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[current_size - 1];
}

template <typename T>
T Queue<T>::pop_front()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	T element = data[0];
	for (int i = 0; i < current_size - 1; i++) {
		data[i] = data[i + 1];
	}
	current_size--;
	return element;
}