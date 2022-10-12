/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:44:43 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 02:45:06 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Constructors
Span::Span() : _max_size(0)
{
	_content = std::vector<int>();
}

Span::Span( const Span &copy ) : _max_size(copy._max_size)
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
Span & Span::operator=(const Span &assign)
{
	std::vector<int>::const_iterator	ass_begin = assign._content.cbegin();
	std::vector<int>::const_iterator	ass_end = assign._content.end();

	this->~Span();
	new (this) Span(assign._max_size);
	
	for ( std::vector<int>::const_iterator it = ass_begin; it < ass_end; it++)
		_content.push_back(*it);

	return (*this);
}


// Getters / Setters
unsigned int Span::getSize() const
{
	return _max_size;
}

//* Logic
void	Span::addNumber( int nbr ) {
	if (_content.size() == _max_size)
		throw MaxSizeExcept();
	else
		_content.insert(
			std::upper_bound(_content.begin(), _content.end(), nbr),
			nbr
		);
}
bool	Span::span_admissible( void ) {
	return (_content.size() > 1);
}
unsigned int	Span::shortestSpan( void ) {
	if (span_admissible()) {
		unsigned int
			shortest = std::numeric_limits<int>::max();
		std::vector<int>::const_iterator
			it;

		for ( it = _content.cbegin() + 1; it < _content.cend(); it++)
			if (std::abs( *it - *(it - 1) ) < int(shortest))
				shortest = *it - *(it - 1);

		return (shortest);
	}
	else
		throw NoSpanExcept();
}
unsigned int	Span::longestSpan( void ) {
	if (span_admissible()) {
		return ( *(_content.cend() - 1) -  *_content.cbegin() );
	}
	else
		throw NoSpanExcept();
}
void	Span::fill(
	std::vector<int>::const_iterator begin,
	std::vector<int>::const_iterator end
)
{
	std::vector<int>::const_iterator	it;

	for ( it = begin; it < end; it++ )
		this->addNumber(*it);
}

//* iterators
std::vector<int>::const_iterator	Span::cbegin() const {
	return (_content.cbegin());
}
std::vector<int>::const_iterator	Span::cend() const {
	return (_content.cend());
}
std::vector<int>::iterator	Span::begin() {
	return (_content.begin());
}
std::vector<int>::iterator	Span::end() {
	return (_content.end());
}

//* other operators

std::ostream&	operator<<(std::ostream& stream, const Span& span) {
	std::vector<int>::const_iterator	it;

	for ( it = span.cbegin(); it < span.cend(); it++ ) 
		stream << it - span.cbegin() << "-th element: " << *it << std::endl;
	
	return (stream);
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
