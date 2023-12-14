/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:43:41 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/14 16:42:21 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "\033[1;31mERROR: Input must be as follows -> ./btc inputFile \nPlease, try again.\033[0m" << std::endl;
		return 1; 
	}
	std::cout << "TESTING!!" << std::endl;

	BitcoinExchange test(av[1]);
	std::cout << test.getFileName() << std::endl;
}