/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 21:35:13 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/01 10:36:33 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

//Orthodox Canonical Form
Serializer::Serializer(){}

Serializer::Serializer(Serializer const & src)
{
	(void) src;
}

Serializer& Serializer::operator=(Serializer const &obj)
{
	(void)obj;
	return *this;
}

Serializer::~Serializer(){}

//methods

/// @brief Serialize: The serialize function takes a pointer to a Data structure and converts it into a simpler, often more linear, representation that can be easily stored or transmitted. In the example provided earlier, it converts a pointer to a Data object into an unsigned integer (uintptr_t) using reinterpret_cast.
/// @param Data* ptr
/// @return unsigned integer (uintptr_t) using reinterpret_cast
uintptr_t Serializer::serialize(Data* ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}


/// @brief Deserialize: The deserialize function, on the other hand, takes the serialized representation (in this case, an unsigned integer) and reconstructs the original data structure. It converts the serialized integer back into a pointer to a Data object using reinterpret_cast
/// @param uintptr_t
/// @return pointer to a Data object
Data* Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

//reinterpret_cast -> is a type of casting operator in C++ that allows you to convert a pointer of one type to a pointer of another type,
//or to convert any integral type to any pointer type, and vice versa
