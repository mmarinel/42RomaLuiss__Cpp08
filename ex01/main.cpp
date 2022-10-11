/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarinel <mmarinel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 22:39:35 by mmarinel          #+#    #+#             */
/*   Updated: 2022/10/11 23:26:24 by mmarinel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Span.hpp"

# include <iostream>
# include <string>

int main( void )
{
	Span	pippo(5);
	std::vector<int> vec = std::vector<int>();

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);

	pippo.fill(vec.cbegin(), vec.cend());
	return 0;
}
