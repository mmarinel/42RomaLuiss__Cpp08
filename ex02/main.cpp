/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 13:12:16 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include "templates.hpp"
# include "Awesome.hpp"

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>

int main(int argc, char const *argv[])
{
	if (argc == 3)
	{
		{
			std::cout << GREEN "|||| int tests" RESET << std::endl;
			//* ************************************************
			
			const size_t		CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t		RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<int>	stack(CONTAINER_SIZE);
			s_elRandom<int>		randomer = s_elRandom<int>(RAND_LIMIT, &random_int);
			
			srand(time(NULL));
			::iter(stack, &s_elRandom<int>::elRandom_ref, randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<int>();
		}
		{
			std::cout << GREEN "||| std::string tests" RESET << std::endl;
			//* ************************************************
			
			const size_t				CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t				RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<std::string>	stack(CONTAINER_SIZE);
			s_elRandom<std::string>		randomer = s_elRandom<std::string>(RAND_LIMIT, &random_string);
			
			srand(time(NULL));
			::iter(stack, &s_elRandom<std::string>::elRandom_ref, randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<std::string>();
		}
		{
			std::cout << GREEN "||| Awesome class tests" RESET << std::endl;
			//* ************************************************
			
			const size_t				CONTAINER_SIZE = std::atoi(argv[1]);
			const size_t				RAND_LIMIT = std::atoi(argv[2]);
			MutantStack<Awesome>	stack(CONTAINER_SIZE);
			s_elRandom<Awesome>		randomer = s_elRandom<Awesome>(RAND_LIMIT, &random_awesome);
			
			srand(time(NULL));
			::iter(stack, &s_elRandom<Awesome>::elRandom_ref, randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<Awesome>();
		}
	}
	return 0;
}
