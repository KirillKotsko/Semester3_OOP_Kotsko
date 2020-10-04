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


