/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/20 18:37:14 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main()
{
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