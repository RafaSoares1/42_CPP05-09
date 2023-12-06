/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:02:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 22:51:08 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

	try
	{
		std::vector<int> container;
		
		container.push_back(18);
		container.push_back(3);
		container.push_back(72);
		container.push_back(63);
		container.push_back(1);

		container.insert(container.begin() + 2, 87);//place new int in [2]
			
		std::cout << "Vector elements: ";
		for (std::vector<int>::iterator it = container.begin(); it != container.end(); ++it) 
		{
			std::cout << *it << " ";
		}
		std::cout << "\n" << std::endl;

		easyfind(container, 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}