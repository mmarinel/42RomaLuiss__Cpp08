/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 16:06:14 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
#define TEMPLATES_H

# include "Awesome.hpp"

# include <unistd.h>
# include <iostream>
# include <cstdlib>
# include <algorithm>

# define safe_delete(o) {delete o; o = nullptr;}

template <typename T>
struct s_elRandom {
	
	typedef T(*rand_el)(int);
	
	public:
		//* Constructors
		s_elRandom( int limit, rand_el rand_handle ) : _limit(limit), _rand_handle(rand_handle) {}
		
		/**
		 * @brief this function returns a random element of type T.
		 * It assumes seed has already been set.
		 * 
		 * @tparam T 
		 * @return T 
		 */
		T	elRandom_ret( void ) {
			return (_rand_handle(_limit));
		}
		/**
		 * @brief this function sets arg to a random value of type T.
		 * It assumes seed has already been set.
		 * 
		 * @tparam T 
		 * @param el 
		 */
		void	elRandom_ref( T& el ) {
			el = _rand_handle(_limit);
		}
	private:
		const int		_limit;//* interpretation changes based on concrete instantiation of type T
		const rand_el	_rand_handle;
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

	while ( it != end_it ) {
		(wrapper.*map)(*it);
		it++;
	}
}

template <typename T>
inline void	print_el( T el ) {
	std::cout << el << std::endl;
}

template <typename T>
inline void	placement_delete( T* o ) {
	o->~T();
}

inline int	random_int( int limit ) {
	return ( std::rand() % (limit + 1) );
}

inline std::string	random_string( int len ) {
	std::string		str;
	size_t			real_len;
	const size_t	STR_MAX_LEN = 50;

	real_len = std::min<size_t>(len, STR_MAX_LEN);
	str = std::string(real_len, '\0');
	for ( size_t i = 0; i < real_len; i++) {
		do {
			str[i] = static_cast<char>(rand() % std::numeric_limits<char>::max());
		} while (false == std::isprint(str[i]));
	}

	return (str);
}

inline Awesome	random_awesome( int nbr ) {
	return (Awesome( std::rand() & (nbr + 1)));
}

#endif /* TEMPLATES_H */
