/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:15:01 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/20 18:29:19 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _requiredGrade;
		const int _gradeToExecute;
	public:
		Form();
		Form(Form & src);
		Form &operator=(Form const& obj);
		~Form();
		Form(std::string name, int required, int execute);
		std::string getName();
		bool getSigned();
		int	getRequired();
		int	getExecute();
		void beSigned(Bureaucrat& bureaucrat);
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

std::ostream& operator<<(std::ostream& o, Form& obj);

#endif