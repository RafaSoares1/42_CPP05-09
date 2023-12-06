/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 21:06:25 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/06 22:43:47 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP


#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class NotFoundException : public std::exception
{
  public:
	  virtual const char *what() const throw() { return ("Exception: Not found, try again.");}
};

template <typename T>
void easyfind(T& container, int value)
{
	if(std::find(container.begin(), container.end(), value) != container.end())
		std::cout << "Number: " << value << " found in the container!" << std::endl;
	else
		throw NotFoundException();
}

#endif