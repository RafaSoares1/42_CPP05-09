/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/23 11:18:29 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{ 
  {
    std::cout << "\033[1;32mTest 1: Shrubbery TEST VALID\033[0m" << std::endl;
    AForm*form = NULL;
    try
    {
      Intern test1;
  
      Bureaucrat bureaucrat("rafa", 1);
      form = test1.makeForm("shrubbery creation", "Target");
      
      std::cout << *form << std::endl;
      form->beSigned(bureaucrat);
      std::cout << *form << std::endl;
      bureaucrat.executeForm(*form);
      delete form;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      delete form;
    }
  }
  {
    std::cout << "\033[1;32mTest 2: PRESIDENTIAL TEST VALID\033[0m" << std::endl;
    AForm*form = NULL;
    try
    {
      Intern test2;
  
      Bureaucrat bureaucrat("rafa", 1);
      form = test2.makeForm("presidential pardon", "Target");
      
      std::cout << *form << std::endl;
      form->beSigned(bureaucrat);
      std::cout << *form << std::endl;
      bureaucrat.executeForm(*form);
      delete form;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      delete form;
    }
  }
  {
    std::cout << "\033[1;32mTest 3: ROBOTOMY TEST VALID\033[0m" << std::endl;
    AForm*form = NULL;
    try
    {
      Intern test3;
  
      Bureaucrat bureaucrat("rafa", 1);
      form = test3.makeForm("robotomy request", "Target");
      
      std::cout << *form << std::endl;
      form->beSigned(bureaucrat);
      std::cout << *form << std::endl;
      bureaucrat.executeForm(*form);
      delete form;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      delete form;
    }
  }
  {
    std::cout << "\033[1;32mTest 4: INVALID TEST\033[0m" << std::endl;
    AForm*form = NULL;
    try
    {
      Intern test4;
  
      Bureaucrat bureaucrat("rafa", 1);
      form = test4.makeForm("error test", "Target");
      
      std::cout << *form << std::endl;
      form->beSigned(bureaucrat);
      std::cout << *form << std::endl;
      bureaucrat.executeForm(*form);
      delete form;
    }
    catch(const std::exception& e)
    {
      std::cerr << e.what() << std::endl;
      delete form;
    }
  }

  return 0;
}