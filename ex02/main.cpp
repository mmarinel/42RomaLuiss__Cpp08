/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 04:53:42 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/14 16:13:11 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "MutantStack.hpp"
# include "templates.hpp"
# include "Awesome.hpp"

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>
# include <list>

void	subject_tests( void );
//* end of static declarations

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
			MutantStack<Awesome>		stack(CONTAINER_SIZE);
			s_elRandom<Awesome>			randomer = s_elRandom<Awesome>(RAND_LIMIT, &random_awesome);
			
			srand(time(NULL));
			::iter(stack, &s_elRandom<Awesome>::elRandom_ref, randomer);
			std::cout << YELLOW << "printing stack using iterator (FIRST RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			std::cout << YELLOW << "printing stack using iterator (SECOND RUN)" << RESET << std::endl;
			std::cout << stack << std::endl;
			stack = MutantStack<Awesome>();
		}
	}
	else
	{
			//*				SUBJECT TESTS
			//* ************************************************

			subject_tests();
	}
	return 0;
}

void	subject_tests( void ) {
	{
		std::cout << GREEN "||| testing with MutantStack" RESET << std::endl;
		//* ************************************************
			
		MutantStack<int> mstack;
		
		mstack.push(5);
		mstack.push(17);
		
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	
	}
	{
		std::cout << GREEN "||| testing with std::list" RESET << std::endl;
		//* ************************************************
			
		std::list<int> mstack;
		
		mstack.push_back(5);
		mstack.push_back(17);
		
		std::cout << mstack.front() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}
	std::cout << std::endl;
}