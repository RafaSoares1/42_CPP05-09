/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:35:19 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/01 10:20:07 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	int value;
};

class Serializer
{
	private:
		//The constructors and destructor is placed in the private section to make the class effectively non-instantiable by users
		Serializer();
		Serializer(Serializer const & src);
		Serializer &operator=(Serializer const &obj);
		~Serializer();
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

//uintptr_t -> It stands for "unsigned integer type capable of holding a pointer."
// can be useful in situations where you need to convert between pointers and integers without losing information


#endif