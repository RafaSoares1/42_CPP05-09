/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 11:29:09 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
  std::cout << "\033[1;32mTest 1: Wrong grade values\033[0m" << std::endl;
	try
	{
    Bureaucrat bureaucrat("Rafa",9);
    Form form("formName", 8, 15);
    bureaucrat.signForm(form);
    std::cout << form << std::endl;
  }
	catch (std::exception &e)
	{
    std::cout << e.what() << std::endl;
  }

  std::cout << "\033[1;32mTest 2: Correct form\033[0m" << std::endl;
  try
	{
    Bureaucrat bureaucrat("Rafa",9);
    Form form("formName", 10, 15);
    bureaucrat.signForm(form);
    std::cout << form << std::endl;
  }
	catch (std::exception &e)
	{
    std::cout << e.what() << std::endl;
  }
  return 0;
}