/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyFind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 10:59:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/15 15:26:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASY_FIND_H
#define EASY_FIND_H

# include <iostream>
# include <stdexcept>
# include <algorithm>

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
int	easyfind( T& container, int to_find ) {
	typename T::iterator	it;
	typename T::iterator	start = container.begin();
	typename T::iterator	end = container.end();

	it = find(start, end, to_find);
	if ( it != end ) {
		std::cout << YELLOW
			<< to_find << " found at position: " << it - start
			<< RESET << std::endl;
		return (*it);
	}
	else
		throw std::out_of_range("easyfind: " RED "el not found" RESET);
}

#endif /* TEMPLATES_H */
