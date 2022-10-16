/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 14:20:41 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATES_H
#define TEMPLATES_H

# include <unistd.h>
# include <iostream>
# include <cstdlib>

template <typename T>
struct s_elRandom {
	
	typedef T(*t_at_random)( int rand_lim );

	public:
		//* Constructors
		s_elRandom( int limit, t_at_random at_random ) : _limit(limit), _at_random(at_random) {}
		
		void	operator() ( T& el ) {
			el = _at_random( _limit + 1 );
		}
		
	private:
		const int	_limit;
		t_at_random	_at_random;
};

template <typename T>
void	print_el( T el ) {
	std::cout << el << std::endl;
}

#endif /* TEMPLATES_H */