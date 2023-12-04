/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:44:54 by emsoares          #+#    #+#             */
/*   Updated: 2023/12/04 11:32:02 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"

Base::~Base(){}

Base * generate(void)
{
	srand(time(0));
	int i = rand() % 3;
	
	switch (i)
	{
	case 0:
		std::cout << "A instanciated to Base" << std::endl;
		return(new A());
	case 1:
		std::cout << "B instanciated to Base" << std::endl;
		return(new B());
	case 2:
		std::cout << "C instanciated to Base" << std::endl;
		return(new C());
	default:
		std::cout << "Invalid instance!" << std::endl;
		break;
	}
	return (NULL);
}

void identify(Base* p)
{
	if(A* a = dynamic_cast<A*>(p))
		std::cout << "A pointer type" << std::endl;
	else if (B* b = dynamic_cast<B*>(p))
		std::cout << "B pointer type" << std::endl;
	else if (C* c = dynamic_cast<C*>(p))
		std::cout << "C pointer type" << std::endl;
	else
		std::cout << "Error pointer type!" << std::endl;
}

void identify(Base& p)
{
  try
	{
    // Attempt to dynamic_cast to each type, and print the corresponding type
    A& a = dynamic_cast<A&>(p);
    std::cout << "A reference type" << std::endl;
		(void) a;
  } 
	catch (const std::exception& e){}
  try 
	{
    B& b = dynamic_cast<B&>(p);
    std::cout << "B reference type" << std::endl;
  	(void) b;
	}
	catch (const std::exception& e) {}
  try
	{
    C& c = dynamic_cast<C&>(p);
    std::cout << "C reference type" << std::endl;
	(void) c;
	} 
	catch (const std::exception& e) {}
}

/*  Using try-catch blocks in the identify(Base& p) function is necessary to handle the case where the dynamic cast fails.
 If the object referred to by p is not of the expected type, dynamic_cast will return nullptr (or throw a std::bad_cast exception in the case of references). */