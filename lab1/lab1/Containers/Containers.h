/**
*   @file Containers.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include "IContainer.h"

/**
* @brief Class Container 
*
* Base class of stack, queue, deque.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Container : public IContainer<T> {
public:

	// Constructor
	Container(int = 30);
	
	// Destructor
	~Container();

	void push_back(const T&) override;
	bool empty() override;
	int max_size() const override;
	int size() const override;
protected:
	// Storage of data
	T* data;
	// Current size of container
	int current_size;
	// Maximal size of container
	int maxsize;
};

template <typename T>
Container<T>::Container(int size) : maxsize(size)
{
	current_size = 0;
	data = new T[maxsize];
}

template <typename T>
Container<T>::~Container()
{
	delete[] data;
}

template <typename T>
bool Container<T>::empty()
{
	return (current_size == 0) ? true : false;
}

template <typename T>
int Container<T>::size() const
{
	return current_size;
}

template <typename T>
int Container<T>::max_size() const
{
	return maxsize;
}

template <typename T>
void Container<T>::push_back(const T& value)
{
	if (current_size == maxsize) throw "Container is full!!!";
	data[current_size++] = value;
}