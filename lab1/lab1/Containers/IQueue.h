/**
*	@file IQueue.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>

/**
 * @brief Represents a collection of objects
 *
 * The IQueue<T> is the base interface of Queue.
 * @tparam T Type of elements inside containers.
 */
template <typename T>
class IQueue {
public:

	/**
	* Destructs the deque.
	*/
	virtual ~IQueue() = default;

	/**
	* Remove first element
	*
	* @return This element
	*/
	virtual T pop_front() = 0;

	/**
	* Access first element
	*
	* @return This element
	*/
	virtual const T& front() = 0;

	/**
	* Access top element
	*
	* @return This element
	*/
	virtual const T& back() = 0;
};