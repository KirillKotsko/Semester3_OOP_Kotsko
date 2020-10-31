/**
*	@file IContainer.h
*	@author Kirill Kotsko
*	@version 1.2
*/

#pragma once
#include <iostream>
#include <exception>

/**
 * @brief Represents a collection of objects
 *
 * The IContainer<T> is the base interface of all containers.
 * @tparam T Type of elements inside containers.
 */
template <typename T>
class IContainer {
public:

	/**
	* Destructs the container.
	*/
	virtual ~IContainer() = default;
	
	/**
	* Add element at the end
	*/
	virtual void push_back(const T&) = 0;

	/**
	* Test whether container is empty
	*
	* @return true ore false
	*/
	virtual bool empty() = 0;

	/**
	* Return maximum size of container
	*
	* @return max size
	*/
	virtual int max_size() const = 0;

	/**
	* Return current size of container
	*
	* @return size
	*/
	virtual int size() const = 0;
};