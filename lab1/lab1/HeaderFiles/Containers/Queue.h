#pragma once
#include <iostream>
#include <exception>
#include "Deque.h"

using namespace std;

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
