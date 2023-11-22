/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:15:01 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 15:40:54 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _requiredGrade;
		const int _gradeToExecute;
	public:
		AForm();
		AForm(AForm & src);
		AForm &operator=(AForm const& obj);
		~AForm();
		AForm(std::string name, int required, int execute);
		std::string getName()const ;
		bool getSigned() const;
		int	getRequired();
		int	getExecute() const;
		void beSigned(Bureaucrat& bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Form Exception: Grade too high!";}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Form Exception: Grade too low!";};
		};
		class NotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Form Exception: Form not signed!";};
		};
};

std::ostream& operator<<(std::ostream& o, AForm& obj);

#endif