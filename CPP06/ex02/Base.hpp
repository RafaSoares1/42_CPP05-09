/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:36:40 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/01 13:18:48 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>
#include <cstdlib>

class Base
{
	public:
		virtual ~Base();
};

Base * generate(void);

void identify(Base* p);

void identify(Base& p);

//https://dev.to/dinhluanbmt/c-check-object-class-type-258d

#endif