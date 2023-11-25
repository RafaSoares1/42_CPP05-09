/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:04:26 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/25 12:29:34 by emsoares         ###   ########.fr       */
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