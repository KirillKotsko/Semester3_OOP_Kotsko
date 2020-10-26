/**
*	@file IDeque.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>

/**
 * @brief Represents a collection of objects
 *
 * The IDeque<T> is the base interface of deque.
 * @tparam T Type of elements inside containers.
 */
template <typename T>
class IDeque {
public:

	/**
	* Destructs the deque.
	*/
	virtual ~IDeque() = default;

	/**
	* Add element at the begin
	*/
	virtual void push_front(const T&) = 0;
};