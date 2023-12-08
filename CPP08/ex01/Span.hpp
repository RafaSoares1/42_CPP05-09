/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:06:58 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/08 15:16:36 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>

class Span
{
	private:
		unsigned int _n;
		std::vector<int> vec;
	public:
		Span();
		Span(unsigned int n);
		Span(const Span & obj);
		Span &operator=(Span const& obj);
		~Span();
		void addNumber(int num);
		int shortestSpan();
		int longestSpan();
		void printVec();

	class SpanFullException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Span already full!";}
		};

	class NotEnoughNumbersException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Not enough numbers to find a span!";}
		};
};

#endif