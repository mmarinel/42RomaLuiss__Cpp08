/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/13 17:32:33 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include "templates.hpp"

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>

int main(int argc, char const *argv[])
{
	if (argc == 3)
	{
		const size_t		CONTAINER_SIZE = std::atoi(argv[1]);
		const size_t		RAND_LIMIT = std::atoi(argv[2]);
		MutantStack<int>	stack(CONTAINER_SIZE);
		s_elRandom<int>		randomer = s_elRandom<int>(RAND_LIMIT);
		
		srand(time(NULL));
		::iter(stack, &s_elRandom<int>::elRandom_int, randomer);
		std::cout << stack;
	}
	return 0;
}
