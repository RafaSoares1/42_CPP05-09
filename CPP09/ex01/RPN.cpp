/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:32:52 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/21 18:05:09 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

//Orthodox Canonical Form
RPN::RPN() : _expression("Default")
{
	executeRPN();
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
	executeRPN();
}


//Get and set functions

void RPN::setExpression(std::string expression)
{
	this->_expression = expression;
}

std::string RPN::getExpression(void)
{
	return (_expression);
}


// performe RPN

void RPN::executeRPN(void)
{
	std::istringstream iss(_expression);
  std::string token;
	
	while(iss >> token)
	{
		if(isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
		{
			_stack.push(std::atof(token.c_str()));
		}
		else
		{
			double value2 = _stack.top();
      _stack.pop();
      double value1 = _stack.top();
	    _stack.pop();
			
			if(token == "+")
				_stack.push(value1 + value2);
			else if(token == "-")
				_stack.push(value1 - value2);
			else if(token == "*")
				_stack.push(value1 * value2);
			else if(token == "/")
				_stack.push(value1 / value2);
			else
			{
				std::cout << "ERROR, INVALID OPERATOR!" << std::endl;	
				return ;
			}
		}
	}
	if (!_stack.empty())
		std::cout << _stack.top() << std::endl;
}