/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:14:50 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 15:30:52 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("Default AForm"), _signed(false), _requiredGrade(150), _gradeToExecute(150)
{
  std::cout << " AForm default constructor called!" << std::endl;
}

AForm::AForm(AForm & src) : _name(src._name), _signed(src._signed), _requiredGrade(src._requiredGrade), _gradeToExecute(src._gradeToExecute)
{
  std::cout << "Copy constructed called!" << std::endl;
}

AForm &AForm::operator=(AForm const& obj)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_signed = obj._signed;
  return *this;
}

AForm::AForm(std::string name, int required, int execute) : _name(name), _signed(false), _requiredGrade(required), _gradeToExecute(execute)
{
  std::cout << "AForm constructor with arguments called!" << std::endl;
  if (_requiredGrade < 1 || _gradeToExecute < 1)
    throw AForm::GradeTooHighException();
  if (_requiredGrade > 150 || _gradeToExecute > 150)
    throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
  std::cout << "AForm destructor called!" << std::endl;
}

std::string AForm::getName() const
{
	return this->_name;
}

bool AForm::getSigned() const
{
	return this->_signed;
}

int AForm::getRequired()
{
	return this->_requiredGrade;
}

int AForm::getExecute() const
{
	return this->_gradeToExecute;
}

void	AForm::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGrade)
		throw GradeTooLowException();
  _signed = true;
}

std::ostream& operator<<(std::ostream& o, AForm& obj)
{
	o << "AForm attributes-> name: " << obj.getName() << " , Signed: " << obj.getSigned() << " , Required Value: " << obj.getRequired() << " , Execute Value: " << obj.getExecute() << std::endl;
  return o;
}
