/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 10:36:09 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/25 12:28:30 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>

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
		static void	printChar(const std::string& literal);
};


#endif