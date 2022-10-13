/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.iterator.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:08:06 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/13 17:53:29 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_ITERATOR_H
# define MUTANTSTACK_ITERATOR_H

# include "MutantStack.hpp"

//* Constructors and destructor
template <typename T>
MutantStack<T>::iterator::~iterator() {
	size_t	i;
	size_t	backupSize = _backup.size();
	size_t	traversedSize = _traversed.size();

	for ( i = 0; i < backupSize; i++ )
		_backup.pop();
	for ( i = 0; i < traversedSize; i++ )
		_traversed.pop();
}

/**
 * @brief returns a new iterator pointing past the last element of the given stack
 * 
 * @tparam T 
 */
template <typename T>
MutantStack<T>::iterator::iterator( void ) {
	_backup = std::stack<T>();
	_traversed = std::stack<T>();
}

/**
 * @brief returns a new iterator pointing to the first element of the given stack
 * 
 * @tparam T 
 * @param s 
 */
template <typename T>
MutantStack<T>::iterator::iterator( std::stack<T> s ) {
	_backup = s;
	_traversed = std::stack<T>();
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
		_backup = to_copy._backup;
		_traversed = to_copy._traversed;

		return (*this);
	}

template <typename T>
bool	MutantStack<T>::iterator::operator==( const iterator& other ) const {
	return (_backup == other._backup && _traversed == other._traversed);
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=( const iterator& other ) const {
	return (_backup != other._backup || _traversed != other._traversed);
}

template <typename T>
bool	MutantStack<T>::iterator::operator>( const iterator& other ) const {
	return (
		_backup.size() < other._backup.size()
		&&
		other + (other._backup.size() - _backup.size()) == *this
	);
}

template <typename T>
bool	MutantStack<T>::iterator::operator<( const iterator& other ) const {
	return (
		_backup.size() > other._backup.size()
		&&
		*this + (_backup.size() - other._backup.size()) == other
	);
}

template <typename T>
bool	MutantStack<T>::iterator::operator>=( const iterator& other ) const {
	return ( *this > other || *this == other);
}

template <typename T>
bool	MutantStack<T>::iterator::operator<=( const iterator& other ) const {
	return ( *this < other || *this == other);
}

template <typename T>
T&	MutantStack<T>::iterator::operator*() {
	return (_backup.top());
}

template <typename T>
T&	MutantStack<T>::iterator::operator[]( int offset ) {
	if (offset < 0 || offset > _backup.size() - 1)
		throw (std::out_of_range(RED "out_of_range excpt: MutantStack operator[]" RESET));
	else
		return (*(this + offset));
}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator+( size_t offset ) const {
		iterator	new_it;

		if (offset < 0 || offset > _backup.size() - 1)
			throw (std::out_of_range(RED "out_of_range excpt: MutantStack operator[]" RESET));
		else {
			new_it = *this;//* Copies current (this) iterator into new one
			while (offset--)
			{
				new_it._traversed.push(new_it._backup.top());
				new_it._backup.pop();
			}
			return (new_it);
		}
	}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator-( size_t offset ) const {
		iterator	new_it;

		if (offset < 0)
			return (this->operator+(-offset));
		else {
			if ( offset > _traversed().size() - 1)
				throw (std::out_of_range(RED "out_of_range excpt: MutantStack operator[]" RESET));
			else {
				new_it = *this;//* Copies current (this) iterator into new one
				while (offset--)
				{
					new_it._backup.push(new_it._traversed.top());
					new_it._traversed.pop();
				}
				return (new_it);
			}
		}
	}

template <typename T>
__SIZE_TYPE__
	MutantStack<T>::iterator::operator-( const iterator& other ) const {
		int	offset;

		offset = other._backup.size() - this->_backup.size();
		if (offset < 0
			|| other + offset != *this)
			throw (std::invalid_argument(RED "invalid_argument excpt: MutantStack operator-" RESET));
		else
			return (offset);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator++() {

		*this = *this + 1;

		return (*this);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator--() {

		*this = *this - 1;

		return  (*this);
	}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator++( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this = *this + 1;

		return  (old_it);
	}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator--( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this = *this - 1;

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