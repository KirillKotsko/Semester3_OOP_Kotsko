#pragma once
#include <iostream>
#include <exception>

using namespace std;

template <typename T>
class Deque {
public:
	Deque(int a = 30);
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
	T* data;
	int current_size;
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

template <typename T>
class Stack {
public:
	Stack(int a = 30) : stack(Deque<T>(a)) {}

	T pop() { return stack.pop_back(); };
	const T& peek() { return stack.back(); };
	void push(const T& value) { stack.push_back(value); };
	bool empty() { return stack.empty(); };
	int max_size() const { return stack.max_size(); };
	int size() const { return stack.size(); };
private:
	Deque<T> stack;
};

template <typename T>
class Queue {
public:
	Queue(int a = 30) : queue(Deque<T>(a)) {}

	void push(const T& value) { queue.push_back(value); };
	bool empty() { return queue.empty(); };
	int max_size() const { return queue.max_size(); };
	int size() const { return queue.size(); };
	T pop() { return queue.pop_front(); };
	const T& front() { return queue.front(); };
	const T& back() { return queue.back(); };
private:
	Deque<T> queue;
};
