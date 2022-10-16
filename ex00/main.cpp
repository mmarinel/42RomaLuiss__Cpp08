/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:57 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/16 13:07:52 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <vector>
# include <iostream>
# include <string>
# include <cmath>
# include <stdlib.h>
# include <time.h>

# include "easyFind.hpp"
# include "templates.hpp"
# include "../colors.hpp"

# define CONTAINER_SIZE 100
# define TO_FIND 42

/**
 * @brief this function returns a random integer in range [-rand_lim, rand_lim].
 *  It assumes seed has already been set.
 * 
 * @param rand_lim 
 * @return int 
 */
static int	rand_int( int rand_lim ) {
	return ( std::pow(-1, rand() % 2) * ( rand() % ( rand_lim + 1 ) ) );
}
//* end of static declarations

int main(int argc, char const *argv[])
{
	(void) argc, (void) argv;
	
	std::vector<int>	v(CONTAINER_SIZE);

	srand(time(NULL));
	//*............Making a container.............
	s_elRandom<int>	randomer = s_elRandom<int>(42);
	std::for_each(v.begin(), v.end(), randomer);
	// ::iter(v, &s_elRandom<int>::elRandom_int, randomer);
	std::cout << "vector is" << std::endl;
	// ::iter(v, print_el<int>);
	std::cout << std::endl;
	
	//*.............Finding element..............
	std::cout << "finding " << TO_FIND << std::endl;
	try {
		std::cout << easyfind(v, TO_FIND) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	
	return 0;
}
