/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:51:57 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/11 18:59:00 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <vector>
# include <iostream>
# include <string>
# include <stdlib.h>
# include <time.h>

# include "easyFind.hpp"
# include "templates.hpp"
# include "../colors.hpp"

# define CONTAINER_SIZE 100
# define TO_FIND 42

int main(int argc, char const *argv[])
{
	(void) argc, (void) argv;
	
	std::vector<int>	v(CONTAINER_SIZE);

	//*............Making container.............
	srand(time(NULL));
	s_elRandom<int>	randomer	= s_elRandom<int>(42);
	::iter(v, &s_elRandom<int>::elRandom_int, randomer);
	std::cout << "vector is" << std::endl;
	::iter(v, print_el<int>);
	std::cout << std::endl;
	
	//*.............Finding element..............
	std::cout << "finding " << TO_FIND << std::endl;
	try {
		std::cout << easyfind(v, TO_FIND) << std::endl;
	}
	catch (const std::exception& e) {
		std::cout << RED << "el could not be found" << RESET << std::endl;
	}
	std::cout << std::endl;

	
	return 0;
}
