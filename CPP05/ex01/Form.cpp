/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:14:50 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 11:14:05 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("Default Form"), _signed(false), _requiredGrade(150), _gradeToExecute(150)
{
  std::cout << " Form default constructor called!" << std::endl;
}

Form::Form(Form & src) : _name(src._name), _signed(src._signed), _requiredGrade(src._requiredGrade), _gradeToExecute(src._gradeToExecute)
{
  std::cout << "Copy constructed called!" << std::endl;
}

Form &Form::operator=(Form const& obj)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_signed = obj._signed;
  return *this;
}

Form::Form(std::string name, int required, int execute) : _name(name), _signed(false), _requiredGrade(required), _gradeToExecute(execute)
{
  std::cout << "Form constructor with arguments called!" << std::endl;
  if (_requiredGrade < 1 || _gradeToExecute < 1)
    throw Form::GradeTooHighException();
  if (_requiredGrade > 150 || _gradeToExecute > 150)
    throw Form::GradeTooLowException();
}

Form::~Form()
{
  std::cout << "Form destructor called!" << std::endl;
}

std::string Form::getName()
{
	return this->_name;
}

bool Form::getSigned()
{
	return this->_signed;
}

int Form::getRequired()
{
	return this->_requiredGrade;
}

int Form::getExecute()
{
	return this->_gradeToExecute;
}

void	Form::beSigned(Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _requiredGrade)
		throw GradeTooLowException();
  _signed = true;
}

std::ostream& operator<<(std::ostream& o, Form& obj)
{
	o << "Form attributes-> name: " << obj.getName() << " , Signed: " << obj.getSigned() << " , Required Value: " << obj.getRequired() << " , Execute Value: " << obj.getExecute() << std::endl;
  return o;
}
