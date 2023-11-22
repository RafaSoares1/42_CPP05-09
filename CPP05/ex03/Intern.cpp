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

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string strArray[] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	
	int i;
	for(i = 0; i < 3; i++)
	{
		if (strArray[i] == name)
			break;
	}
	switch (i)
	{
	case 0:
	{
		std::cout << "Intern creates " << name << std::endl;
		return new RobotomyRequestForm(target);
	}
	case 1:
	{
		std::cout << "Intern creates " << name << std::endl;
		return new PresidentialPardonForm(target);
	}
	case 2:
	{
		std::cout << "Intern creates " << name << std::endl;
		return new ShrubberyCreationForm(target);
	}
	default:
		break;
	}
	std::cout << "Intern couldnt create anything !!!" << std::endl;
	return NULL;
}