/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:04:49 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/27 17:17:41 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

//Orthodox Canonical Form
ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(ScalarConverter const & src)
{
	(void) src;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &obj)
{
	(void)obj;
	return *this;
}

ScalarConverter::~ScalarConverter(){}

//Aux functions

bool ScalarConverter::ftIsPrintable(int c)
{
	if (c >= 32 && c <= 126)
		return true;
	return false;
}

//isType
bool ScalarConverter::isChar(const std::string& literal)
{
	if(literal.length() > 1)
		return false;
	if(literal[0] >= '0' && literal[0] <= '9')
		return false;
	return true;
}

bool ScalarConverter::isInt(const std::string& literal)
{
	for(size_t i = 0; i < literal.length(); i++)
	{
		if (i == 0 && literal[i] == '-')
			continue;
		if(!isdigit(literal[i]))
			return false;
	}
	long n = atol(literal.c_str());
	if (n < std::numeric_limits<int>::min() || n > std::numeric_limits<int>::max())
		return false;
	return true;	
}

//printType

void	ScalarConverter::printChar(char c)
{
	if(ftIsPrintable(c))
		std::cout << "char: " << c << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(c) << ".0" << std::endl;
}

void	ScalarConverter::printInt(int n)
{
	if(ftIsPrintable(n))
		std::cout << "char: " << static_cast<char>(n) << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<float>(n) << ".0" << std::endl;
}

//Scalar Converter
void ScalarConverter::convert(const std::string& literal)
{
	std::cout << "----SCALAR CONVERTER----\n" << std::endl;
	if(isChar(literal))
		printChar(literal[0]);
	else if(isInt(literal))
		printInt(atoi(literal.c_str()));
	else
		std::cout << "Error !!!!" << std::endl;
}

