#pragma once
#include <iostream>
#include <exception>

using namespace std;

//1. Πεΰλ³ηΰφ³ÿ stack

template <typename T>
class Stack {
public:
	Stack(int = 30);
	~Stack();

	void push(const T&);
	T pop();
	const T& peek();
	bool empty();
	int size() const;
private:
	T* data;
	int current_index;
	const int maxsize;
};

template <typename T>
Stack<T>::Stack(int size) : maxsize(size)
{
	current_index = 0;
	data = new T[maxsize];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] data;
}

template <typename T>
void Stack<T>::push(const T& value)
{
	if (current_index == maxsize) throw exception("Stack is full!!!");
	data[current_index++] = value;
}

template <typename T>
T Stack<T>::pop()
{
	if (current_index == 0) throw exception("Stack is empty!!!");
	return data[--current_index];
}

template <typename T>
const T& Stack<T>::peek()
{
	if (current_index == 0) throw exception("Stack is empty!!!");
	return data[current_index - 1];
}

template <typename T>
bool Stack<T>::empty()
{
	return (current_index == 0) ? true : false;
}

template <typename T>
int Stack<T>::size() const
{
	return current_index;
}

// 2. Πεΰλ³ηΰφ³ÿ queue

template <typename F>
class Queue {
public:
	Queue(int = 30);
	~Queue();

	void push(const F&);
	F pop();
	const F& front();
	const F& back();
	bool empty();
	int size() const;
private:
	F* data;
	int current_size;
	int maxsize;
};

template <typename F>
Queue<F>::Queue(int size) : maxsize(size)
{
	current_size = 0;
	data = new F[maxsize];
}

template <typename F>
Queue<F>::~Queue()
{
	delete[] data;
}

template <typename F>
void Queue<F>::push(const F& value)
{
	if (current_size == maxsize) throw exception("Queue is full!!!");
	data[current_size++] = value;
}

template <typename F>
const F& Queue<F>::front()
{
	if (current_size == 0) throw exception("Queue is empty!!!");
	return data[0];
}

template <typename F>
const F& Queue<F>::back()
{
	if (current_size == 0) throw exception("Queue is empty!!!");
	return data[current_size - 1];
}

template <typename F>
F Queue<F>::pop()
{
	if (current_size == 0) throw exception("Queue is empty!!!");
	F element = data[0];
	for (int i = 0; i < current_size - 1; i++) {
		data[i] = data[i + 1];
	}
	current_size--;
	return element;
}

template <typename F>
bool Queue<F>::empty()
{
	return (current_size == 0) ? true : false;
}

template <typename F>
int Queue<F>::size() const
{
	return current_size;
}

// 3. Πεΰλ³ηΰφ³ÿ deque

template <typename M>
class Deque {
public:
	Deque(int = 30);
	~Deque();

	void push_back(const M&);
	void push_front(const M&);
	M pop_back();
	M pop_front();
	const M& front();
	const M& back();
	bool empty();
	int size() const;
private:
	M* data;
	int current_size;
	int maxsize;
};

template <typename M>
Deque<M>::Deque(int size) : maxsize(size)
{
	current_size = 0;
	data = new M[maxsize];
}

template <typename M>
Deque<M>::~Deque()
{
	delete[] data;
}

template <typename M>
bool Deque<M>::empty()
{
	return (current_size == 0) ? true : false;
}

template <typename M>
int Deque<M>::size() const
{
	return current_size;
}

template <typename M>
const M& Deque<M>::front()
{
	if (current_size == 0) throw exception("Deque is empty!!!");
	return data[0];
}

template <typename M>
const M& Deque<M>::back()
{
	if (current_size == 0) throw exception("Deque is empty!!!");
	return data[current_size - 1];
}

template <typename M>
void Deque<M>::push_back(const M& value)
{
	if (current_size == maxsize) throw exception("Deque is full!!!");
	data[current_size++] = value;
}

template <typename M>
void Deque<M>::push_front(const M& value)
{
	if (current_size == maxsize) throw exception("Deque is full!!!");
	for (int i = current_size; i > 0; i--) data[i] = data[i - 1];
	current_size++;
	data[0] = value;
}

template <typename M>
M Deque<M>::pop_front()
{
	if (current_size == 0) throw exception("Deque is empty!!!");
	M element = data[0];
	for (int i = 0; i < current_size - 1; i++) {
		data[i] = data[i + 1];
	}
	current_size--;
	return element;
}

template <typename M>
M Deque<M>::pop_back()
{
	if (current_size == 0) throw exception("Deque is empty!!!");
	return data[--current_size];
}
