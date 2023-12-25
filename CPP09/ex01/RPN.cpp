/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:32:52 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/25 13:46:03 by emsoares         ###   ########.fr       */
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
	if(this->isValidExpression() == false)
		throw WrongExpressionException();
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

//verify expression
bool RPN::isValidExpression()
{
	std::istringstream iss(_expression); // This stream is used to extract individual tokens from the expression.
  std::string index;
  while (iss >> index)
	{
  	// Check if the index is a single-digit number or a valid operator
  	if (!((index.size() == 1 && isdigit(index[0])) || (index.size() == 1 && std::string("+-*/").find(index[0]) != std::string::npos)))
  	  return false; // If the current token is neither a single-digit number nor a valid operator, the function returns false immediately, indicating that the expression is not valid.
  }
  return true;
}

// performe RPN

void RPN::executeRPN(void)
{
	std::istringstream iss(_expression); // This stream is used to extract individual tokens from the expression.
  std::string index;
	
	while(iss >> index)
	{
		if(isdigit(index[0]))
			_stack.push(std::atof(index.c_str()));
		else
		{
			double value2 = _stack.top();
      _stack.pop();
      double value1 = _stack.top();
	    _stack.pop();
			
			if(index == "+")
				_stack.push(value1 + value2);
			else if(index == "-")
				_stack.push(value1 - value2);
			else if(index == "*")
				_stack.push(value1 * value2);
			else if(index == "/")
				_stack.push(value1 / value2);
			else
				throw WrongExpressionException();
		}
	}
	if (!_stack.empty())
		std::cout << _stack.top() << std::endl;
}