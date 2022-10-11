/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/11 19:02:48 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
#define TEMPLATES_H

# include <unistd.h>
# include <iostream>
# include <cstdlib>

template <typename T>
struct s_elRandom {
	public:
		//* Constructors
		s_elRandom( int limit ) : _limit(limit) {}
		
		//* Logic
		/**
		 * @brief this function fills a container of ints with values ranging in [0, limit].
		 * It assumes seed has already been set.
		 * 
		 * @tparam T 
		 * @param el 
		 * @return T 
		 */
		T	elRandom_int( T& el ) {
			el = static_cast<T>(std::rand() % (_limit + 1));
			return (el);
		}
	private:
		const int	_limit;
};

template <typename T, typename FPTR>
void	iter( T& container, FPTR map ) {
	typename T::iterator	it;
	typename T::iterator	end_it;

	it = container.begin();
	end_it = container.end();

	while (it != end_it) {
		map(*it);
		it++;
	}
}

//* I tried creating a closure (as a type) but it got too ugly and too verbose...
template <typename T, typename FPTR, typename F_Wrapper>
void	iter( T& container, FPTR map, F_Wrapper& wrapper ) {
	typename T::iterator	it;
	typename T::iterator	end_it;

	it = container.begin();
	end_it = container.end();

	while (it != end_it) {
		(wrapper.*map)(*it);
		it++;
	}
}

template <typename T>
void	print_el( T el ) {
	std::cout << el << std::endl;
}

#endif /* TEMPLATES_H */
