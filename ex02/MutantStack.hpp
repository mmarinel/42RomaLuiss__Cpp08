/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:08:47 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 12:24:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <string>
# include <stack>
# include <deque>
# include <stdexcept>

# include "../colors.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		struct	iterator {
			public:
				// Constructors
				iterator();
				iterator( typename std::deque<T>::iterator it );
				iterator( const iterator& to_copy );
				
				// Destructors
				~iterator();
				
				// Operators
				const iterator&			operator=( const iterator& to_copy );
				bool					operator==( const iterator& other ) const;
				bool					operator!=( const iterator& other ) const;
				bool					operator>( const iterator& other ) const;
				bool					operator<( const iterator& other ) const;
				bool					operator>=( const iterator& other ) const;
				bool					operator<=( const iterator& other ) const;
				T&						operator*();
				T&						operator[]( int offset );
				iterator				operator+( size_t offset ) const;
				iterator				operator-( size_t offset ) const;
				__SIZE_TYPE__			operator-( const iterator& other )  const;
				iterator&				operator++();
				iterator				operator++( int placeholder );
				iterator&				operator--();
				iterator				operator--( int placeholder );
				iterator&				operator+=( size_t offset );
				iterator&				operator-=( size_t offset );
			
			private:
				typename std::deque<T>::iterator	it;
		};
		
		// Constructors
		MutantStack();
		MutantStack( size_t size );
		MutantStack( const MutantStack &copy );
		
		// Destructor
		~MutantStack();
		
		// Operators
		const MutantStack& operator=( const MutantStack &assign );
		
		//* Logic
		const T&		top( void ) const;
		bool			empty( void ) const;
		__SIZE_TYPE__	size( void ) const;
		void			push( T& el );
		void			pop( void );
		
		//* iterators
		iterator	begin( void );
		iterator	end( void );
};

// Stream operators
template <typename T>
std::ostream& operator<<( std::ostream &stream, const MutantStack<T> &mut_stack );

# include "MutantStack.tpp"
# include "MutantStack.iterator.tpp"

#endif