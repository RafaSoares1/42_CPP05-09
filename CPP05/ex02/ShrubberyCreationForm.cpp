/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:22:00 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 17:11:47 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default Target")
{
	std::cout << "ShrubberyCreationForm " << _target << " default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm & src) : AForm(src), _target(src._target)
{
	std::cout << "Copy constructed called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& obj)
{
	std::cout << "ShrubberyCreationForm " << _target << " Copy assignment operator called" << std::endl;
  if (this != &obj)
		this->_target = obj._target;
  return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << _target << " destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm " << _target << " constructor with args called" << std::endl;
}

std::string ShrubberyCreationForm::getTarget()
{
	return _target;
}

void ShrubberyCreationForm::executeShrubbery() const
{
	std::string filename = _target + "_shrubbery";
	std::ofstream outputFile(filename.c_str());
	if(outputFile.is_open())
	{
		outputFile << "       _-_        " << std::endl;
		outputFile << "    /~~   ~~\\    " << std::endl;
		outputFile << " /~~         ~~\\ " << std::endl;
		outputFile << "{               } " << std::endl;
		outputFile << " \\  _-     -_  / " << std::endl;
		outputFile << "   ~  \\ //  ~    " << std::endl;
		outputFile << "_- -   | | _-     " << std::endl;
		outputFile << "  _ -  | |   -_   " << std::endl;
		outputFile << "      // \\       " << std::endl;
		outputFile << "##################" << std::endl;
		outputFile.close();

		std::cout << "(EXTRA) File created: " << filename << std::endl;
	}
	else
	{
		std::cout << "Error opening file for writing: " << filename << std::endl;
	}
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (this->getSigned() == false)
		throw AForm::NotSignedException();
	if (executor.getGrade() > this->getExecute())
		throw AForm::GradeTooLowException();
	executeShrubbery();
}