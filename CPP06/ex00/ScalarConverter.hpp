/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:36:09 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/30 21:34:12 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <stdlib.h>
#include <cfloat>

class ScalarConverter
{
	private:
		//The constructors and destructor is placed in the private section to make the class effectively non-instantiable by users
		ScalarConverter();
		ScalarConverter(ScalarConverter const & src);
		ScalarConverter &operator=(ScalarConverter const &obj);
		~ScalarConverter();
	public:
    static void convert(const std::string& literal);
		static bool	isChar(const std::string& literal);
		static bool isInt(const std::string& literal);
		static bool isFloat(const std::string& literal);
		static bool isDouble(const std::string& literal);
		static bool isSpecial(const std::string& literal);
		static void	printChar(char c);
		static void printInt(int n);
		static void printFloat(const std::string& literal);
		static void printDouble(const std::string& literal);
		static void printSpecial(const std::string& literal);
		static bool ftIsPrintable(int c);
};


#endif