/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:01:27 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 14:56:20 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm & src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const& obj);
		~ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		std::string getTarget();
		void	executeShrubbery() const;
		void	execute(Bureaucrat const & executor) const;
};



#endif