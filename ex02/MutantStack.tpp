/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:34:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 19:33:06 by mmarinel         ###   ########.fr       */
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
MutantStack<T>::MutantStack( const MutantStack& copy ) {
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack<T>() {}

template <typename T>
const MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& assign ) {
	for (size_t i = 0; i < _stack.size(); i++)
		_stack.pop();
	_stack = assign._stack;
}

template <typename T>
const T&	MutantStack<T>::top( void ) {
	return (_stack.top());
}

template <typename T>
bool	MutantStack<T>::empty( void ) {
	return (_stack.empty());
}

template <typename T>
__SIZE_TYPE__	MutantStack<T>::size( void ) {
	return (_stack.size());
}

template <typename T>
void	MutantStack<T>::push( T el ) {
	return (_stack.push(el));
}

template <typename T>
T&	MutantStack<T>::pop( void ) {
	return (_stack.pop());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin( void ) {
	return (iterator(_stack));
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end( void ) {
	return (iterator());
}

#endif