/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:34:18 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 11:08:58 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	//INT!
	try
	{
		std::cout << "-----INT TEST-----\n" << std::endl;
		Array<int> arrayINT(6);
		std::cout << arrayINT.size() << std::endl;
		Array<int> arrayINT2(arrayINT);
		std::cout << arrayINT.size() << std::endl;
		std::cout << arrayINT2[3] << std::endl;

		for(unsigned int i = 0; i < arrayINT.size(); i++)
			std::cout << arrayINT[i];
		std::cout << std::endl;

		for(unsigned int i = 0; i < arrayINT.size(); i++)
			arrayINT[i] = i + 1;
		std::cout << std::endl;
		
		for(unsigned int i = 0; i < arrayINT.size(); i++)
			std::cout << arrayINT[i];
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	//Char
	try
	{
		std::cout << "\n-----Char TEST-----\n" << std::endl;
		Array<char> arrayChar(6);
		std::cout << arrayChar.size() << std::endl;
		Array<char> arrayChar2;
		arrayChar2 = arrayChar;
		std::cout << arrayChar.size() << std::endl;
		std::cout << arrayChar2[3] << std::endl;//vai printar o '\0'

		for(unsigned int i = 0; i < arrayChar.size(); i++)
			std::cout << arrayChar[i]; //vai printar '\0'
		std::cout << "array done";
		std::cout << std::endl;

		for(unsigned int i = 0; i < arrayChar.size(); i++)
			arrayChar[i] = i + 65;
		std::cout << std::endl;
		
		for(unsigned int i = 0; i < arrayChar.size(); i++)
			std::cout << arrayChar[i];
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		std::cout << "\n-----ERROR TEST-----\n" << std::endl;
		Array<int> arrayINT(6);
		arrayINT[7];
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

}