/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inter.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 11:47:43 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/22 12:02:52 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define	INTERN_HPP

#include "AForm.hpp"


class Intern
{
	public:
		Intern();
		Intern(Intern & src);
		Intern &operator=(Intern const& obj);
		~Intern();
		AForm *makeForm(const std::string name,const std::string target);
		AForm* createRobotomy(const std::string target);
		AForm* createPresidential(const std::string target);
		AForm* createShrubbery(const std::string target);
		class ErrorFormNameException : public std::exception
		{
			public:
				virtual const char* what() const throw(){return "Form name not recognized!";};
		};
};


#endif