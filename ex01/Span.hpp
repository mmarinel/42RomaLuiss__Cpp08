/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:43:33 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 00:29:19 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <string>
# include <vector>
# include <algorithm>
# include <iterator>
# include <cmath>

class Span
{
	public:
		typedef std::vector<int>::iterator iterator;
		typedef std::vector<int>::const_iterator const_iterator;

		// Constructors
		Span();
		Span( const Span &copy );
		Span( unsigned int max_size );
		
		// Destructor
		~Span();
		
		// Operators
		Span & operator=( const Span &assign );
		
		// Getters / Setters
		unsigned int getSize() const;
		
		//* Logic
		void				addNumber( int nbr );
		void				fill(
			std::vector<int>::const_iterator	begin,
			std::vector<int>::const_iterator	end
		);
		unsigned int		shortest_span( void );
		unsigned int		longest_span( void );

		//* iterators
		std::vector<int>::const_iterator	cbegin() const;
		std::vector<int>::iterator			begin();
		std::vector<int>::const_iterator	cend() const;
		std::vector<int>::iterator			end();

		// Exceptions
		class NoSpanExcept : public std::exception {
			virtual const char* what() const throw();
		};
		class MaxSizeExcept : public std::exception {
			virtual const char* what() const throw();
		};
		
	private:
		std::vector<int>		_content;
		const unsigned int 		_max_size;
		bool					span_admissible( void );
		
};

std::ostream&	operator<<(std::ostream& stream, const Span& span);

#endif