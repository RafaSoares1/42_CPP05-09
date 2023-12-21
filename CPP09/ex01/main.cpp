/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:31:33 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/21 17:39:28 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
	{
		std::cout << "\033[1;31mERROR: Input must be as follows -> ./RPN mathematical_expression \nPlease, try again.\033[0m" << std::endl;
		return 1; 
	}
	RPN test(av[1]);
	
}