/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:04:57 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/01 14:34:40 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

int main()
{
	Base *test = generate();
	// Identify and print the type using the pointer version
  identify(test);

  // Identify and print the type using the reference version
	identify(*test);  // Dereference the pointer to pass it by reference
  
	/* Base& test2 = *test; //Creating a reference to the object test
	// Now, both test and test2 refer to the same object
	identify(test2); */
	delete test;
}