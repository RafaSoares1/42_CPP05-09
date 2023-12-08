/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:07:05 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/08 17:06:20 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	try
	{
		std::cout << "TESTING Copy constructor AND Copy assignment operator\n" << std::endl;
		Span test(6);
		
		test.addNumber(2);
		test.addNumber(24);
		test.addNumber(241);
		test.addNumber(242);
		test.addNumber(243);

		std::cout << "test obj: ";	
		test.printVec();

		Span test2(test);
		std::cout << "test2 obj: ";
		test2.printVec();

		Span test3(4);
		test3 = test2;
		test3.addNumber(294);
		std::cout << "test3 obj: ";
		test3.printVec();
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "\n\nLongest/shortest span\n" << std::endl;
		Span a(6);
		
		a.addNumber(2);
		a.addNumber(10);
		a.addNumber(4);
		a.addNumber(14);
		a.addNumber(19);
		
		std::cout << "a obj: ";	
		a.printVec();
		std::cout  << a.shortestSpan() << " is the Shortest Span.\n" <<std::endl;
		std::cout  << a.longestSpan() << " is the Longest Span." <<std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
}