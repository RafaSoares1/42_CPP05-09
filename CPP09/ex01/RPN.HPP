/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.HPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:33:00 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/20 17:43:01 by emsoares         ###   ########.fr       */
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
	
		//performeRPN

};

#endif