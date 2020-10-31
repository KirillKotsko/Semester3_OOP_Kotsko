/**
*	@file IStack.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>

/**
 * @brief Represents a collection of objects
 *
 * The IStack<T> is the base interface of stack.
 * @tparam T Type of elements inside containers.
 */
template <typename T>
class IStack {
public:

	/**
	* Destructs the deque.
	*/
	virtual ~IStack() = default;

	/**
	* Remove top element
	*
	* @return This element
	*/
	virtual T pop_back() = 0;

	/**
	* Access top element
	*
	* @return This element
	*/
	virtual const T& peek() = 0;
};
