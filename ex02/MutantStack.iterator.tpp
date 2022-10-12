/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.iterator.tpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 05:08:06 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 05:59:42 by mmarinel         ###   ########.fr       */
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

const T&	MutantStack<T>::iterator::operator*() {
	return (_backup.top());
}

const T&	MutantStack<T>::iterator::operator[]( int offset ) {
	if (offset < 0 || offset > size() - 1)
		throw (std::out_of_range());
	else
		return (*(this + offset));
}

typename MutantStack<T>::iterator&
	MutantStack<T>::iterator::operator+( size_t offset ) {
		
	}