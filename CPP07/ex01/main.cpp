/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:02:03 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 11:55:10 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	std::cout <<"INT " << std::endl;
	
	int array[] = {1, 2, 3, 4, 5};
	
	iter(array, 5, changeValue);
	std::cout << std::endl;

	std::cout << "Array of ints after applying changeValue function: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << "\n\n----------------------------" << std::endl;
	//-------------------------------------------
	
	std::cout <<"\nDOUBLE " << std::endl;
	
	double arrayD[] = {1.33, 2.50, 4.25, 3.45, 9.6};
	
	iter(arrayD, 5, changeValue);
	std::cout << std::endl;

	std::cout << "Array of doubles after applying changeValue function: ";
	for (int i = 0; i < 5; ++i) {
		std::cout << arrayD[i] << " ";
	}
	std::cout << "\n\n----------------------------" << std::endl;
	
	std::cout <<"\nSTRING " << std::endl;
	std::string arrayStr = "rafael";
	std::cout << "\nString : " << std::endl;
	iter(arrayStr.c_str(), arrayStr.length(), printArray);
	std::cout << std::endl;
}
