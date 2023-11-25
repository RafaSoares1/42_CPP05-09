/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 11:04:49 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/25 12:28:39 by emsoares         ###   ########.fr       */
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

//isType
bool ScalarConverter::isChar(const std::string& literal)
{
	if(literal.length() > 1)
		return false;
	if(literal[0] >= '0' && literal[0] <= '9')
		return false;
	if(literal[0] >= 32 && literal[0] <= 126)
		return true;
	return false;
}

//printType

void	ScalarConverter::printChar(const std::string& literal)
{
	std::cout << "char: " << literal << std::endl;
}

//Scalar Converter
void ScalarConverter::convert(const std::string& literal)
{
	std::cout << "----SCARL CONVERTER----\n" << std::endl;
	if(isChar(literal))
		printChar(literal);
	else
		std::cout << "Error !!!!" << std::endl;

}

