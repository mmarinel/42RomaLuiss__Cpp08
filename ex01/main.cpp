/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/12 00:52:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include "templates.hpp"

# include <iostream>
# include <string>

# include <stdlib.h>
# include <time.h>

# define CONTAINER_SIZE 100000

int main( void )
{
	srand(time(NULL));

	Span				pippo(CONTAINER_SIZE);
	std::vector<int>	vec = std::vector<int>(CONTAINER_SIZE);
	s_elRandom<int>		randomer(420000);

	::iter(vec, &s_elRandom<int>::elRandom_int, randomer);
	pippo.fill(vec.cbegin(), vec.cend());
	std::cout << pippo << std::endl;
	// ::iter(pippo, &print_el<int>);
	return 0;
}
