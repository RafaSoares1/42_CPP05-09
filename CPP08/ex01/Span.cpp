/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:06:51 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/08 17:16:03 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _n(0){}

Span::Span(unsigned int n) : _n(n){}

Span::Span(const Span & obj) : _n(obj._n), vec(obj.vec){}

Span &Span::operator=(Span const& obj)
{
	if(this != &obj)
	{
		vec.clear();
		_n = obj._n;
		vec = obj.vec;
	}
	return *this;
}

Span::~Span(){}

void Span::addNumber(int num)
{
	if (vec.size() >= _n)
		throw SpanFullException();
	vec.push_back(num);
}

void Span::printVec()
{
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n" <<std::endl;
}

int Span::shortestSpan()
{
	if(vec.size() <= 1)//check if there are enough elements to fin a span
		throw NotEnoughNumbersException();
	
	int min = std::numeric_limits<int>::max();
	int a;
	int b;
	for(std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
	{
		for(std::vector<int>::iterator it2 = vec.begin(); it2 != vec.end(); it2++)	
		{
			if(it == it2)
				continue;
			if(std::abs(*it - *it2) < min)
			{
				min = std::abs(*it - *it2);
				a = *it;
				b = *it2;
			}
		}
	}
	std::cout << a << " and " << b << " are the two values to calculate shortestSpan." <<std::endl;
	return min;
}
int Span::longestSpan()
{
	if(vec.size() <= 1)//check if there are enough elements to fin a span
		throw NotEnoughNumbersException();
	
	std::vector<int> sortVec = vec;
	std::sort(sortVec.begin(), sortVec.end());
	
	int min = sortVec.front();
	int max = sortVec.back();
	
	std::cout << min << " and " << max << " are the two values to calculate longestSpan." <<std::endl;
	return (max-min);

}

