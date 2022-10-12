/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:08:47 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 06:12:49 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <stdexcept>

template <typename T>
class MutantStack
{
	struct	iterator {
		public:
			// Constructors
			iterator( void );
			iterator( std::stack<T> s );
			iterator( const iterator& to_copy );
			
			// Destructors
			~iterator();
			
			// Operators
			const iterator&			operator=( const iterator& to_copy );
			bool					operator==( const iterator& other );
			bool					operator!=( const iterator& other );
			const T&				operator*();
			const T&				operator[]( int offset );
			iterator				operator+( size_t offset );
			iterator				operator-( size_t offset );
			iterator&				operator++();
			iterator				operator++( int placeholder );
			iterator&				operator--();
			iterator				operator--( int placeholder );
			iterator&				operator+=( size_t offset );
			iterator&				operator-=( size_t offset );
			bool					operator>( size_t offset );
			bool					operator<( size_t offset );
			bool					operator>=( size_t offset );
			bool					operator<=( size_t offset );

		private:
			std::stack<T>	_backup;
			std::stack<T>	_traversed;
	};
	public:
		// Constructors
		MutantStack();
		MutantStack( const MutantStack &copy );
		
		// Destructor
		~MutantStack();
		
		// Operators
		const MutantStack& operator=( const MutantStack &assign );
		
		//* Logic
		const T&		top( void );
		bool			empty( void );
		__SIZE_TYPE__	size( void );
		void			push( T el );
		T&				pop( void );
		
		//* iterators
		iterator	begin( void );
		iterator	end( void );
		
	private:
		std::stack<T> _stack;
		
};

// Stream operators
// std::ostream & operator<<( std::ostream &stream, const MutantStack &object );

# include "MutantStack.tpp"
# include "MutantStack.iterator.tpp"

#endif