/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.CPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:32:52 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/20 17:42:44 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.HPP"

//Orthodox Canonical Form
RPN::RPN() : _expression("Default")
{
	
}

RPN::RPN(const RPN& obj)
{
	(void)obj;
}

RPN& RPN::operator=(const RPN& obj)
{
	(void)obj;
  return (*this);
}

RPN::~RPN(){}

//Constructor with argument
RPN::RPN(std::string input) : _expression(input)
{
}


//Get and set functions

void RPN::setExpression(std::string expression)
{
	this._expression = expression;
}

std::string RPN::getExpression(void)
{
	return (_expression);
}