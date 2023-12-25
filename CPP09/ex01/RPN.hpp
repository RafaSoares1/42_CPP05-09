/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:33:00 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/25 12:29:30 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stack>

class RPN
{
	private:
		std::string _expression;
		std::stack<double> _stack;
		RPN(const RPN& obj);
    RPN& operator=(const RPN& obj);
	
	public:
		RPN();
		RPN(std::string input);
    ~RPN();
		void	setExpression(std::string expression);
		std::string	getExpression(void);
		bool isValidExpression();
		void	executeRPN(void);
	
		class WrongExpressionException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Incorrect expression!\nPlease try again!";}
		};
};

#endif