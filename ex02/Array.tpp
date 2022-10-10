/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:44:32 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:06:57 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <typename T>
size_t	Array<T>::size() const {
	return (this->__size);
}

template <typename T>
T&			Array<T>::operator[]( size_t index ) {
	if ( index < 0 || index >= this->__size)
		throw (std::exception());
	else
		return (this->__array[index]);
}

template <typename T>
const T&			Array<T>::operator[]( size_t index ) const {
	if ( index < 0 || index >= this->__size)
		throw (std::exception());
	else
		return (this->__array[index]);
}

template <typename T>
const Array<T>&	Array<T>::operator=(const Array &assign) {
	this->~Array();
	this->__array = new T[assign.__size];
	this->__size = assign.__size;
	
	for (size_t i = 0; i < this->__size; i++)
		this->__array[i] = assign.__array[i];//* T has overload the '=' for real-deepcopy to happen!
	
	return (*this);
}

template <typename T>
Array<T>::~Array() {
	delete[] this->__array;
	this->__array = nullptr;
	this->__size = 0;
	std::cout << RED << "<<Array Destroyed>>" << RESET << std::endl;
}


template <typename T>
Array<T>::Array(const Array &copy) : __array(nullptr) {
	std::cout << GREEN << "Array Copy Constructor called" << RESET << std::endl;
	
	*this = copy;
}

template <typename T>
Array<T>::Array( size_t _size ) {
	std::cout << GREEN << "Array fields Constructor called" << RESET << std::endl;
	
	this->__array = new T[_size];
	this->__size = _size;
}

template <typename T>
Array<T>::Array() {
	std::cout << GREEN << "Array Default Constructor called" << RESET << std::endl;
	
	this->__array = nullptr;
	this->__size = 0;
}

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array) {
	for (size_t i = 0; i < array.size(); i++) {
		std::cout << "array[" << i << "] = " << array[i] << std::endl;
	}
	return (stream);
}

#endif