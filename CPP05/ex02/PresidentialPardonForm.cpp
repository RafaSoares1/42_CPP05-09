/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:29 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 18:40:31 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default Target")
{
	std::cout << "PresidentialPardonForm " << _target << " default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm & src) : AForm(src), _target(src._target)
{
	std::cout << "Copy constructed called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& obj)
{
	std::cout << "PresidentialPardonForm " << _target << " Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_target = obj._target;
  return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << _target << " destructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm " << _target << " constructor with args called" << std::endl;
}

std::string PresidentialPardonForm::getTarget()
{
	return _target;
}

void PresidentialPardonForm::executePresidential() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
	executePresidential();
}