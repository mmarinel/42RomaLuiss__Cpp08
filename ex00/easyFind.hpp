/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 17:41:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

# include <iostream>
# include <stdexcept>

# include "../colors.hpp"

/**
 * @brief this function template returns a const reference to the first occurrence
 * of a given integer in a container of integers. If no elements are found, an exception is thrown.
 * 
 * @tparam T 
 * @param container 
 * @param to_find 
 * @return const T& 
 */
template <typename T>
int	easyfind( const T& container, int to_find ) {
	typename T::const_iterator	it;
	typename T::const_iterator	begin_it;
	typename T::const_iterator	end_it;

	begin_it = container.cbegin();
	end_it = container.cend();

	it = begin_it;
	while (it != end_it) {
		if (*it == to_find)
		{
			std::cout
				<< YELLOW
				<< "occurrence found at pos "
				<< it - begin_it
				<< RESET
				<< std::endl;
			return (static_cast<int>(*it));
		}
		it++;
	}
	throw std::exception();
}

#endif /* TEMPLATES_H */
