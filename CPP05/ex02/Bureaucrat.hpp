/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:48:52 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 18:04:22 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include "AForm.hpp"

class AForm; // forward declaration

class Bureaucrat
{
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(Bureaucrat & src);
		Bureaucrat &operator=(Bureaucrat const& obj);
		~Bureaucrat();
		Bureaucrat(std::string name, int grade);
		const std::string getName();
		int getGrade() const;
		void	setGrade(int grade);
		void	incrementGrade();
		void	decrementGrade();
		void  signForm(AForm& form);
		void	executeForm(AForm const & form) const;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Exception: Grade too high!";}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Exception: Grade too low!";};
		};
};
std::ostream& operator<<(std::ostream& o, Bureaucrat& obj);


#endif