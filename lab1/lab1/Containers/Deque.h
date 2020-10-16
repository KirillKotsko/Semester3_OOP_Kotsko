#pragma once
/**
*	@file Deque.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>

using namespace std;


/**
* @brief Class Deque (double-ended queue)
*
* Represent all neccessary methods.
* @tparam T type of data to storage in this container.
*/
template <typename T>
class Deque {
public:
	// Constructor
	Deque(int a = 30);
	// Deconstructor
	~Deque();

	T pop_front();
	const T& front();
	const T& back();
	T pop_back();
	void push_back(const T&);
	bool empty();
	int max_size() const;
	int size() const;
	void push_front(const T&);
private:
	// Storage of data
	T* data;
	// Current size of container
	int current_size;
	// Maximal size of container
	int maxsize;
};

template <typename T>
Deque<T>::Deque(int size) : maxsize(size)
{
	current_size = 0;
	data = new T[maxsize];
}

template <typename T>
Deque<T>::~Deque()
{
	delete[] data;
}

template <typename T>
bool Deque<T>::empty()
{
	return (current_size == 0) ? true : false;
}

template <typename T>
int Deque<T>::size() const
{
	return current_size;
}

template <typename T>
int Deque<T>::max_size() const
{
	return maxsize;
}

template <typename T>
void Deque<T>::push_back(const T& value)
{
	if (current_size == maxsize) throw exception("Container is full!!!");
	data[current_size++] = value;
}

template <typename T>
T Deque<T>::pop_back()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[--current_size];
}

template <typename T>
const T& Deque<T>::front()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[0];
}

template <typename T>
const T& Deque<T>::back()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	return data[current_size - 1];
}

template <typename T>
T Deque<T>::pop_front()
{
	if (current_size == 0) throw exception("Container is empty!!!");
	T element = data[0];
	for (int i = 0; i < current_size - 1; i++) {
		data[i] = data[i + 1];
	}
	current_size--;
	return element;
}

template <typename T>
void Deque<T>::push_front(const T& value)
{
	if (current_size == maxsize) throw exception("Container is full!!!");
	for (int i = current_size; i > 0; i--) data[i] = data[i - 1];
	current_size++;
	data[0] = value;
}