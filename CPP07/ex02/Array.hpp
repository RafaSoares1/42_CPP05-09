/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:33:56 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/05 16:32:05 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <class T>
class Array
{
	private:
		unsigned int _n;
		T* _array;
	public:
		Array();
		Array(unsigned int n);
		Array(Array & src);
		Array &operator=(Array const& obj);
		~Array();

		T& operator[](unsigned int i);
				
		unsigned int size(void)const;
		
		class IndexOutOfBoundsException : public std::exception
		{
			public:
				virtual const char *what() const throw(){return "Exception: Index Out Of Bounds";}
		};
};

#endif