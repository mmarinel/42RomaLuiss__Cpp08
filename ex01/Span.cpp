/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:44:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/11 22:11:10 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span() : _max_size(0)
{
	_content = std::vector<int>();
}

Span::Span( const Span &copy )
{
	*this = copy;
}

Span::Span( unsigned int max_size ) : _max_size(max_size)
{
	_content = std::vector<int>();
}


// Destructor
Span::~Span()
{
}


// Operators
Span & Span::operator=(const Span &assign) : _max_size(assign._max_size)
{
	std::vector<int>::const_iterator	ass_begin = assign.cbegin();
	std::vector<int>::const_iterator	ass_end = assign.end();

	this->~Span();
	new (this) Span(assign._max_size);
	
	for ( std::vector<int>::const_iterator it = begin; it < end; it++)
		_conent.push_back(*it);

	return (*this);
}


// Getters / Setters
unsigned int Span::getSize() const
{
	return _size;
}

//* Logic
void	Span::addNumber( int nbr ) {
	if (_content.size() == _max_size)
		throw MaxSizeExcept();
	else
		_content.insert(
			std::upper_bound(_content.begin(), content.end(), nbr),
			item
		);
}
bool	Span::span_admissible( void ) {
	return (_content.size() > 1);
}
unsigned int	Span::shortest_span( void ) {
	if (span_admissible) {
		unsigned int
			shortest = std::numeric_limits<int>::max();
		std::vector<int>::const_iterator
			it;

		for ( it = _content.cbegin() + 1; it < _content.cend(); it++)
			if (std::abs( *it - *(it - 1) ) < shortest)
				shortest = *it - *(it - 1);

		return (shortest);
	}
	else
		throw NoSpanExcept();
}
usnigned int	Span::longest_span( void ) {
	if (span_admissible) {
		return ( *(_content.cend() - 1) -  *_content.cbegin() );
	}
	else
		throw NoSpanExcept();
}
void	Span::fill( std::vector<int> nbrs ) {
	
}
// Exceptions
const char * Span::NoSpanExcept::what() const throw()
{
	return "Span: not enough elements to calculate span";
}
const char * Span::MaxSizeExcept::what() const throw()
{
	return "Span: max capacity reached";
}
