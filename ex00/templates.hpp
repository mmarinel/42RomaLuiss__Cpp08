/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   templates.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 11:56:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 13:01:31 by mmarinel         ###   ########.fr       */
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
		s_elRandom( int limit ) : _limit(limit) {}
		
		void	operator() ( T& el ) {
			el = at_random(std::rand() % (_limit + 1));
		}
		
	private:
		const int	_limit;
		t_at_random	at_random;
};

template <typename T>
void	print_el( T el ) {
	std::cout << el << std::endl;
}

#endif /* TEMPLATES_H */
