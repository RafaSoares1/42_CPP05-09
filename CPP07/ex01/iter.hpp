/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 18:02:23 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 11:54:57 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void iter(T *array, int len, void (*func)(T&))
{
	for (int i = 0; i < len; i++)
		func(array[i]);	
}

template<typename T>
void changeValue(T& t1)
{
	t1 += 1;
}

template<typename T>
void printArray(T t1)
{
	std::cout << t1 << " - ";
}

#endif