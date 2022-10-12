/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.iterator.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:08:06 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 06:29:35 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"

template <typename T>
const typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator=( const iterator& to_copy ) {
		_backup = to_copy._backup;
		_traversed = std::stack<T>();

		return (*this);
	}

template <typename T>
bool	MutantStack<T>::iterator::operator==( const iterator& other ) {
	return (_backup == other._backup && _traversed == other._traversed);
}

template <typename T>
bool	MutantStack<T>::iterator::operator!=( const iterator& other ) {
	return (_backup != other._backup || _traversed != other._traversed);
}

template <typename T>
const T&	MutantStack<T>::iterator::operator*() {
	return (_backup.top());
}

template <typename T>
const T&	MutantStack<T>::iterator::operator[]( int offset ) {
	if (offset < 0 || offset > size() - 1)
		throw (std::out_of_range());
	else
		return (*(this + offset));
}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator+( size_t offset ) {
		iterator	new_it;

		while (offset)
		{
			if (this->_backup.empty())
				throw (std::out_of_range());
			else {
				new_it = *this;
				new_it.traversed.push(new_it._backup.pop());
				offset -= 1;
			}
		}
		
		// if (this->_backup.empty())
		// 	throw (std::out_of_range());
		// else {
		// 	new_it = *this;
		// 	new_it.traversed.push(new_it._backup.pop());
		// }

		return  (new_it);
	}

template <typename T>
typename MutantStack<T>::iterator
	MutantStack<T>::iterator::operator-( size_t offset ) {
		iterator	new_it;

		if (this->_traversed.empty())
			throw (std::out_of_range());
		else {
			new_it = *this;
			new_it._backup.push(new_it._traversed.pop());
		}

		return  (new_it);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator++() {

		*this = *this + 1;

		return  (*this);
	}
//* Aggiungere push ignore dei warnings
template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator++( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this = *this + 1;

		return  (old_it);
	}

template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator--() {

		*this = *this - 1;

		return  (*this);
	}

//* Aggiungere push ignore dei warnings
template <typename T>
typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator--( int placeholder ) {
		iterator	old_it;
		
		old_it = *this;
		*this = *this - 1;

		return  (old_it);
	}
