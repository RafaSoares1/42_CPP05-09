/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:49:02 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/20 16:38:35 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	
	std::cout << "\033[1;32mTest 1: creating a default obj\033[0m" << std::endl;

	{
		Bureaucrat A;
		std::cout << A << std::endl;
	}
	
	std::cout << "\033[1;32mTest 2: creating a obj with args\033[0m" << std::endl;
	{
		Bureaucrat B("Rafael2", 100);
		std::cout << B << std::endl;
		try{
			B.decrementGrade();
			std::cout << "After decrement:\n" << std::endl;
			std::cout << B << std::endl;
		}
		catch(const Bureaucrat::GradeTooLowException &e){
			std	::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[1;32mTest 3: creating a obj with args, but value invalid\033[0m" << std::endl;
	{
		try{
			Bureaucrat B("Rafae3l", 151);
		}
		catch(const Bureaucrat::GradeTooLowException &e){
			std	::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e){
			std	::cout << e.what() << std::endl;
		}
	} //destructor isnt called because constructor is not complete !!!!!

	std::cout << "\033[1;32mTest 4: DECREMENT TEST\033[0m" << std::endl;
	{
		try{
			Bureaucrat B("Rafael4", 150);
			std::cout << B << std::endl;
			B.decrementGrade();
		}
		catch(const Bureaucrat::GradeTooLowException &e){
			std	::cout << e.what() << std::endl;
		}
		catch(const Bureaucrat::GradeTooHighException &e){
			std	::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[1;32mTest 5: INCREMENT TEST\033[0m" << std::endl;
	{
		try{
			Bureaucrat B("Rafael5", 1);
			std::cout << B << std::endl;
			B.incrementGrade();
		}
		catch(const std::exception &e){
			std	::cout << e.what() << std::endl;
		}
	}
	std::cout << "\033[1;32mTest 6: COPY CONSTRUCTOR TEST\033[0m" << std::endl;
	{
		Bureaucrat A("COPY", 22);
		Bureaucrat B(A);

		std::cout << B << std::endl;
	}
}