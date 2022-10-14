/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 19:24:44 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"
# include "templates.hpp"
# include "../colors.hpp"

# include <iostream>
# include <string>

# include <stdlib.h>
# include <time.h>

int main( int argc, const char* argv[])
{
	srand(time(NULL));
	
	if (argc == 3)
	{
		const size_t		CONTAINER_SIZE = std::atoi(argv[1]);
		const size_t		CONTAINER_VALRANGE = std::atoi(argv[2]);
		Span				container(CONTAINER_SIZE);
		std::vector<int>	vec = std::vector<int>(CONTAINER_SIZE);
		s_elRandom<int>		randomer(CONTAINER_VALRANGE);

		//* Filling container
		::iter(vec, &s_elRandom<int>::elRandom_int, randomer);
		container.fill(vec.begin(), vec.end());

		//* Printing output
		std::cout << container << std::endl;
		// exit(0);
		std::cout
			<< YELLOW
			<< "shortest span: "
			<< container.shortestSpan()
			<< "\tlongest span: "
			<< container.longestSpan()
			<< RESET
			<< std::endl;
	}
	else
	{
		std::cout << std::endl << YELLOW << "Subject tests" << RESET << std::endl;

		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << std::endl;
	return 0;
}
