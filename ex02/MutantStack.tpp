/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:34:44 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 11:48:17 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_TPP
# define MUTANTSTACK_TPP

# include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack( size_t size ) : std::stack<T>() {
	for (size_t i = 0; i < size; i++)
		this->c.push_back(T());
}

template <typename T>
MutantStack<T>::MutantStack( const MutantStack& copy ) {
	*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack<T>() {
	for (size_t i = 0; i < this->c.size(); i++)
		this->c.pop_front();
}

template <typename T>
const MutantStack<T>&	MutantStack<T>::operator=( const MutantStack<T>& assign ) {
	this->~MutantStack();
	this->c = assign.c;

	return (*this);
}

template <typename T>
const T&	MutantStack<T>::top( void ) const {
	return (this->c.top());
}

template <typename T>
bool	MutantStack<T>::empty( void ) const {
	return (this->c.empty());
}

template <typename T>
__SIZE_TYPE__	MutantStack<T>::size( void ) const {
	return (this->c.size());
}

template <typename T>
void	MutantStack<T>::push( T& el ) {
	this->c.push_back(el);
}

template <typename T>
void	MutantStack<T>::pop( void ) {
	this->c.pop_front();
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
	return (iterator(this->c.begin()));
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
	return (iterator(this->c.end()));
}

template <typename T>
std::ostream& operator<<( std::ostream &stream, const MutantStack<T> &mut_stack ) {
	MutantStack<T>						copy = mut_stack;//* we need copy because begin is not a const function, so we cannot call it on mut_stack
	typename MutantStack<T>::iterator	it;
	typename MutantStack<T>::iterator	begin = copy.begin();
	typename MutantStack<T>::iterator	end = copy.end();

	for (it = begin; it < end; it++)
		stream << it -  begin << "th element: " << *it << std::endl;

	return (stream);
}

#endif