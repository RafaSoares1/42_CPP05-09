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

bool ScalarConverter::isFloat(const std::string& literal)
{
	if(literal[literal.length() - 1] != 'f')
		return false;
	if(literal.find_first_of('.') != literal.find_last_of('.'))
		return false;

	for(size_t i = 0; i < literal.length() - 1; i++)
	{
		if (i == 0 && literal[i] == '-')
			continue;
		if(literal[i] == '.')
			continue;
		if(!isdigit(literal[i]))
			return false;
	}
	std::string copy = literal;

	copy.erase(copy.length() - 1);
	std::istringstream iss(copy); // creating an istringstream object named iss.
	//The purpose of istringstream is to treat a string (copy in this case) as if it were a stream (like cin or a file).
	//iss is now a stream that you can use to read from the string
	float myFloat;

	if(iss >> myFloat)//checking whether it's possible to extract a floating-point number from the stream (iss) and store it in the variable myFloat
	{
		if (myFloat < -FLT_MAX || myFloat > FLT_MAX)
			return false;
	return true;
	}
	return false;
}

bool ScalarConverter::isDouble(const std::string& literal)
{
	if(literal.find_first_of('.') != literal.find_last_of('.'))
		return false;

	for(size_t i = 0; i < literal.length() - 1; i++)
	{
		if (i == 0 && literal[i] == '-')
			continue;
		if(literal[i] == '.')
			continue;
		if(!isdigit(literal[i]))
			return false;
	}
	std::string copy = literal;

	std::istringstream iss(copy); // creating an istringstream object named iss.
	//The purpose of istringstream is to treat a string (copy in this case) as if it were a stream (like cin or a file).
	//iss is now a stream that you can use to read from the string
	double myDouble;

	if(iss >> myDouble)//checking whether it's possible to extract a floating-point number from the stream (iss) and store it in the variable myDouble
	{
		if (myDouble < -DBL_MAX || myDouble > DBL_MAX )
			return false;
	return true;
	}
	return false;
}

bool ScalarConverter::isSpecial(const std::string& literal)
{
	if (literal == "nan" || literal == "-inf" || literal == "+inf" || literal == "nanf" || literal == "-inff" || literal == "+inff")
		return (true);
	return (false);
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

void ScalarConverter::printFloat(const std::string& literal)
{
	std::string copy = literal;

	copy.erase(copy.length() - 1);
	std::istringstream iss(copy);
	float myFloat;
	if(iss >> myFloat)
	{
		if(ftIsPrintable(static_cast<int>(myFloat)))
			std::cout << "char: " << static_cast<char>(myFloat) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(myFloat) << std::endl;
		std::cout << "float: " << myFloat << "f" << std::endl;
		std::cout << "double: " << myFloat << std::endl;
	}
}

void ScalarConverter::printDouble(const std::string& literal)
{
	std::string copy = literal;

	std::istringstream iss(copy);
	double myDouble;
	if(iss >> myDouble)
	{
		if(ftIsPrintable(static_cast<int>(myDouble)))
			std::cout << "char: " << static_cast<char>(myDouble) << std::endl;
		else
			std::cout << "char: Non displayable" << std::endl;
		std::cout << "int: " << static_cast<int>(myDouble) << std::endl;
		std::cout << "float: " << myDouble << "f" << std::endl;
		std::cout << "double: " << myDouble << std::endl;
	}
}

void ScalarConverter::printSpecial(const std::string& literal)
{
	std::cout << "char : impossible" << std::endl;
	std::cout << "int : impossible" << std::endl;
	if(literal == "-inff" || literal == "+inff" || literal == "nanf")
		std::cout << "float : " << literal << std::endl;
	else
		std::cout << "float : " << literal << "f" << std::endl;
	if (literal == "-inf" || literal == "+inf" || literal == "nan")
		std::cout << "double : " << literal << std::endl;
	else
	{
		std::string copy = literal;
		copy.erase(copy.length() - 1);
		std::cout << "double : " << copy << std::endl;
	}
}
//Scalar Converter
void ScalarConverter::convert(const std::string& literal)
{
	std::cout << "----SCALAR CONVERTER----\n" << std::endl;
	if(isChar(literal))
		printChar(literal[0]);
	else if(isInt(literal))
		printInt(atoi(literal.c_str()));
	else if(isFloat(literal))
		printFloat(literal);
	else if(isDouble(literal))
		printDouble(literal);
	else if(isSpecial(literal))
		printSpecial(literal);
	else
		std::cout << "Error !!!!" << std::endl;
}

