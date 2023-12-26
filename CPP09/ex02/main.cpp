/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:51:07 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/26 15:02:52 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool isDigit(const std::string str)
{
  for (size_t i = 0; i < str.length(); ++i)
  	if (!isdigit(str[i]))
      return false;
  return true;
}


int main(int ac, char **av)
{
	if (ac < 2)
		return(std::cout << "\033[1;31mERROR: Input must be as follows -> ./PmergeMe List of numbers!\nPlease, try again.\033[0m" << std::endl, 1); 
	for(int i = 1; i < ac ; i++)
	{
		if (isDigit(av[i]) == false)
			return(std::cout << "\033[1;31mERROR: Input arguments must contain only number!\033[0m" << std::endl, 1);
	}

	std::vector<int> temp;
	for(int i = 1; i < ac; i++)
	{
		if(atol(av[i]) < INT_MIN || atol(av[i]) > INT_MAX)
			return(std::cout << "\033[1;31mERROR: Input arguments must can't be < INT_MIN or > INT_MAX!\033[0m" << std::endl, 1);	
		else
			temp.push_back(atoi(av[i]));
	}
	
	PmergeMe test(temp);
	
}