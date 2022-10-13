/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.iterator.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:08:06 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/13 22:28:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_ITERATOR_H
# define MUTANTSTACK_ITERATOR_H

# include "MutantStack.hpp"

//* Constructors and destructor
template <typename T>
MutantStack<T>::iterator::~iterator() {
	this->it.~iterator();
}

template <typename T>
MutantStack<T>::iterator::iterator() {
	this->it = typename std::deque<T>::iterator();
}

template <typename T>
MutantStack<T>::iterator::iterator( typename std::deque<T>::iterator it ) {
	this->it = it;
}

template <typename T>
MutantStack<T>::iterator::iterator( const iterator& to_copy ) {
	*this = to_copy;
}


//* ------------------------------------------------------------------------- *//

//* Operators
template <typename T>
const typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator=( const iterator& to_copy ) {

		this->~iterator();
		this->it = to_copy.it;

		return (*this);
	}

template <typename T>
bool	MutantStack<T>::iterator::operator==( const iterator& other ) const {
	return (this->it == other.it);
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=( const iterator& other ) const {
	return (this->it != other.it);
}

template <typename T>
bool	MutantStack<T>::iterator::operator>( const iterator& other ) const {
	return (this->it > other.it);
}

template <typename T>
bool	MutantStack<T>::iterator::operator<( const iterator& other ) const {
	return (this->it < other.it);
}

template <typename T>
bool	MutantStack<T>::iterator::operator>=( const iterator& other ) const {
	return (this->it >= other.it);
}

template <typename T>
bool	MutantStack<T>::iterator::operator<=( const iterator& other ) const {
	return (this->it <= other.it);
}

template <typename T>
T&	MutantStack<T>::iterator::operator*() {
	return (*it);
}

template <typename T>
T&	MutantStack<T>::iterator::operator[]( int offset ) {
	return (this->it[offset]);
}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator+( size_t offset ) const {
		return (this->it + offset);
	}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator-( size_t offset ) const {
		return (this->it - offset);
	}

template <typename T>
__SIZE_TYPE__
	MutantStack<T>::iterator::operator-( const iterator& other ) const {
		return (this->it - other.it);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator++() {

		this->it = this->it + 1;

		return (*this);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator--() {

		this->it = this->it - 1;

		return  (*this);
	}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator++( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this++;

		return  (old_it);
	}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator--( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this--;

		return (old_it);
	}
#pragma GCC diagnostic pop

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator+=( size_t offset ) {
		*this = *this + offset;

		return (*this);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator-=( size_t offset ) {
		*this = *this - offset;

		return (*this);
	}

#endif