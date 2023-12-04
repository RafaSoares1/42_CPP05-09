/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:04:26 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/30 21:34:16 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if(ac != 2)
	{
		return(std::cout << "Error: Invalid number of arguments!\nPlease try again!" << std::endl,1);
	}
	ScalarConverter::convert(av[1]);
}