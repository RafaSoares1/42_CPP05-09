/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:47:33 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/22 17:23:53 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << "Intern constructor called!" << std::endl;
}


Intern::Intern(Intern & src)
{
	(void) src;
}

Intern &Intern::operator=(Intern const& obj)
{
	(void) obj;
	return(*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called!" << std::endl;
}

AForm* Intern::createRobotomy(const std::string target)
{
	std::cout << "Intern creates robotomy request!" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(const std::string target)
{
	std::cout << "Intern creates presidential pardon!" << std::endl;
	return new RobotomyRequestForm(target);
}

AForm* Intern::createShrubbery(const std::string target)
{
	std::cout << "Intern creates shrubbery creation!" << std::endl;
	return new RobotomyRequestForm(target);
}


AForm *Intern::makeForm(const std::string name,const std::string target)
{
	const std::string strArray[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm* (Intern::*formCreator[])(const std::string ) = {&Intern::createRobotomy, &Intern::createPresidential, &Intern::createShrubbery}; // declares an array of function pointers.
	//Each function in the array is expected to take a std::string parameter and return a pointer to an object of type AForm

	for(int i = 0; i < 3; i++)
	{
		if (strArray[i] == name)
			return (this->*formCreator[i])(target);
	}

	throw ErrorFormNameException();
  return NULL;//security reasons!!
}