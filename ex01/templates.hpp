/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/08 15:02:51 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
#define TEMPLATES_H

# include <unistd.h>
# include <iostream>

template <typename T, typename F>
void	iter( T* array, size_t len, F map ) {
	for ( size_t i = 0; i < len; i++ ) {
		map(array[i]);
	}
}

template <typename T>
T	elDouble( T& el ) {
	el += el;
	return (el);
}

template <typename T>
void	print_el( T el ) {
	std::cout << el << std::endl;
}

#endif /* TEMPLATES_H */
