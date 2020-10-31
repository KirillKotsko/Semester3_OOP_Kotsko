/**
*	@file Stack.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include "IStack.h"
#include "Containers.h"

using namespace std;

/**
* @brief Class Stack
*
* Represent all neccessary methods. Composition of the deque class.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Stack : public IStack<T>, virtual public Container<T> {
public:

	// Constructor
	Stack(int a = 30) : Container<T>(a) {}

	T pop_back() override;
	const T& peek() override;
protected:
	// Storage of data
	Container<T>::data;
	// Current size of container
	Container<T>::current_size;
	// Maximal size of container
	Container<T>::maxsize;
};

template <typename T>
T Stack<T>::pop_back()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[--current_size];
}

template <typename T>
const T& Stack<T>::peek()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[current_size - 1];
}