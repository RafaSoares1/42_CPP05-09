/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/22 18:15:27 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
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
  
  return 0;
}