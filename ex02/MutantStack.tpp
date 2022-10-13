/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:34:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/13 15:20:25 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() {
	_stack = std::stack<T>();
}

template <typename T>
MutantStack<T>::MutantStack( size_t size ) {
	this->_stack = std::stack<T>();

	for (size_t i = 0; i < size; i++)
		this->_stack.push(T());
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& copy ) {
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack<T>() {
	for (size_t i = 0; i < _stack.size(); i++)
		_stack.pop();
}

template <typename T>
const MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& assign ) {
	this->~MutantStack();
	_stack = assign._stack;
}

template <typename T>
const T&	MutantStack<T>::top( void ) const {
	return (_stack.top());
}

template <typename T>
bool	MutantStack<T>::empty( void ) const {
	return (_stack.empty());
}

template <typename T>
__SIZE_TYPE__	MutantStack<T>::size( void ) const {
	return (_stack.size());
}

template <typename T>
void	MutantStack<T>::push( T& el ) {
	_stack.push(el);
}

template <typename T>
void	MutantStack<T>::pop( void ) {
	_stack.pop();
}

/**
 * @brief this function returns an iterator
 * pointing to the first element of the mutant stack.
 * The current stack is copied inside the iterator.
 * 
 * @tparam T 
 * @return MutantStack<T>::iterator 
 */
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (iterator(_stack));
}

/**
 * @brief this function returns an iterator
 * pointing past the last element of the mutant stack.
 * The iterator gets an empty stack.
 * 
 * @tparam T 
 * @return MutantStack<T>::iterator 
 */
template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (iterator());
}

template <typename T>
std::ostream& operator<<( std::ostream &stream, const MutantStack<T> &mut_stack ) {
	typename MutantStack<T>::iterator	it;
	typename MutantStack<T>::iterator	begin = mut_stack.begin();
	typename MutantStack<T>::iterator	end = mut_stack.end();

	for (it = begin; it < end; it++)
		stream << it -  begin << "th element: " << *it << std::endl;
}

#endif