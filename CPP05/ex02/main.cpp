/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/22 11:40:22 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
  std::cout << "\033[1;32mTest 1: Shrubbery TEST\033[0m" << std::endl;
	try
	{
    Bureaucrat bureaucrat("Rafa",1);
    ShrubberyCreationForm form1("Shrubbery");
    std::cout << "\n" << std::endl;
    
    bureaucrat.signForm(form1);
    bureaucrat.executeForm(form1);
    std::cout << "\n" << std::endl;

  }
	catch (std::exception &e)
	{
    std::cout << "Constructor error because of: " << e.what() << std::endl;
  }

  std::cout << "\033[1;32m\nTest 2: Robotomy TEST\033[0m" << std::endl;
  try
	{
    Bureaucrat bureaucrat("Rafa",3);
    RobotomyRequestForm form2("Robotomy");
    std::cout << "\n" << std::endl;
    
    bureaucrat.signForm(form2);
    bureaucrat.executeForm(form2);
    std::cout << "\n" << std::endl;

  }
	catch (std::exception &e)
	{
    std::cout << "Constructor error because of: " << e.what() << std::endl;
  }
  std::cout << "\033[1;32m\nTest 3: Presidential TEST\033[0m" << std::endl;
  try
	{
    Bureaucrat bureaucrat("Rafa",6);
    PresidentialPardonForm form3("Robotomy");
    std::cout << "\n" << std::endl;
    
    bureaucrat.signForm(form3);
    bureaucrat.executeForm(form3);
    std::cout << "\n" << std::endl;

  }
	catch (std::exception &e)
	{
    std::cout << "Constructor error because of: " << e.what() << std::endl;
  }
  return 0;
}