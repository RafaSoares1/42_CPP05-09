/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:02:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/11 17:17:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{

	try
	{
		std::cout << "----- Vector test -----\n" << std::endl;

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

		easyfind(container, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "\n----- List test -----\n" << std::endl;

		std::list<int> container2;
		
		container2.push_back(23);
		container2.push_back(31);
		container2.push_back(722);
		container2.push_back(639);
		container2.push_back(123);
		
		// Move the iterator to the desired position using std::advance
		std::list<int>::iterator it = container2.begin();
    std::advance(it, 2); // Move 2 positions forward

    container2.insert(it, 87);// Insert new int at the 3rd position
			
		std::cout << "List elements: ";
		for (std::list<int>::iterator it = container2.begin(); it != container2.end(); ++it) 
		{
			std::cout << *it << " ";
		}
		std::cout << "\n" << std::endl;

		easyfind(container2, 23);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}