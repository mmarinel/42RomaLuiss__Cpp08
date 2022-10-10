/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:13:03 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/09 18:06:22 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include "../colors.hpp"

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		//* Constructors
		Array();
		Array( size_t _size );
		Array(const Array &copy);
		
		//* Destructor
		~Array();
		
		//* Operators
		const Array&	operator=(const Array &assign);
		const T&			operator[]( size_t index ) const;
		T&					operator[]( size_t index );
		
		//* Getters / Setters
		size_t	size() const;
		
	private:
		size_t	__size;
		T*		__array;
		
};

template <typename T>
std::ostream&	operator<<(std::ostream& stream, const Array<T>& array);

# include "Array.tpp"

#endif