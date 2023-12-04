/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:20:33 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/01 14:51:24 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data myData;

	myData.value = 42;
	std::cout << "myData value: " << myData.value << std::endl;

	uintptr_t serializedValue = Serializer::serialize(&myData);
	std::cout << "serialized value: " << serializedValue << std::endl;
	//The output is the result of converting the pointer address of myData to an uintptr_t
	
	// Deserialize the pointer
    Data* deserializedData = Serializer::deserialize(serializedValue); //to validate the deserialization process, use the deserialized pointer to access the value member and print it
    
  // Print the deserialized value
    std::cout << "Deserialized value: " << deserializedData->value << std::endl;
	return 0;

	// By serializing an object, you convert its state into a format that can be easily reconstructed later.
	//Deserialization is the process of taking that serialized format and reconstructing the original object.
	
}