/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:08 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/20 16:50:19 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
  std::cout << " Bureaucrat default constructor called!" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat & src) : _name(src._name), _grade(src._grade)
{
  std::cout << "Copy constructed called!" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const& obj)
{
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_grade = obj._grade;
  return *this;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
  std::cout << "Bureaucrat constructor with arguments called!" << std::endl;
  if (_grade < 1)
    throw Bureaucrat::GradeTooHighException();
  if (_grade > 150)
    throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{
  std::cout << "Bureaucrat destructor called!" << std::endl;
}

const std::string Bureaucrat::getName()
{
	return this->_name;
}

int Bureaucrat::getGrade()
{
	return this->_grade;
}

void  Bureaucrat::setGrade(int grade)
{
  this->_grade = grade;  
}

void	Bureaucrat::incrementGrade()
{
	if (_grade - 1 < 1)
    throw GradeTooHighException();
  else
    this->_grade -= 1;
}

void	Bureaucrat::decrementGrade()
{
	if (_grade + 1 > 150)
    throw GradeTooLowException();
  else
    this->_grade += 1;
}

std::ostream& operator<<(std::ostream& o, Bureaucrat& obj)
{
  o << "Bureaucrat attributes-> grade: " << obj.getGrade() << " , name: " << obj.getName() << std::endl;
  return o;
}
