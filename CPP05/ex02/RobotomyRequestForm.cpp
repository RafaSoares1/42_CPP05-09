/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:26:47 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 18:16:06 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default Target")
{
	std::cout << "RobotomyRequestForm " << _target << " default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm & src) : AForm(src), _target(src._target)
{
	std::cout << "Copy constructed called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& obj)
{
	std::cout << "RobotomyRequestForm " << _target << " Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_target = obj._target;
  return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << _target << " destructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm " << _target << " constructor with args called" << std::endl;
}

std::string RobotomyRequestForm::getTarget()
{
	return _target;
}

void RobotomyRequestForm::executeRobotomy() const
{
	std::cout << "Drilling noises!!!" << std::endl;
	srand(time(NULL));
	int i = (rand() % 2) + 1;
	if(i == 1)
		std::cout << _target << " has been robotomized." << std::endl;
	else //i == 2
		std::cout << _target << " robotomy failed." << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
	executeRobotomy();
}