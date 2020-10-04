#pragma once
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Container {
public:
	Container(int = 30);
	~Container();

	void push_back(const T&);
	bool empty();
	int max_size() const;
	int size() const;
protected:
	T* data;
	int current_size;
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
	if (current_size == maxsize) throw exception("Container is full!!!");
	data[current_size++] = value;
}

//1. Πεΰλ³ηΰφ³ÿ stack

template <typename T>
class Stack : virtual public Container<T> {
public:
	Stack(int a = 30) : Container<T>(a) {}

	T pop_back();
	const T& peek();
protected:
	Container<T>::data;
	Container<T>::current_size;
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

// 2. Πεΰλ³ηΰφ³ÿ queue

template <typename T>
class Queue : virtual public Container<T> {
public:
	Queue(int a = 30) : Container<T>(a) {}

	T pop_front();
	const T& front();
	const T& back();
protected:
	Container<T>::data;
	Container<T>::current_size;
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