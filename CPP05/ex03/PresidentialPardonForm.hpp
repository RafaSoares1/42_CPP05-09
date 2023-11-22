/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:35:46 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 18:39:08 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm 
{
	private:
		std::string _target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm & src);
		PresidentialPardonForm &operator=(PresidentialPardonForm const& obj);
		~PresidentialPardonForm();
		PresidentialPardonForm(std::string target);
		std::string getTarget();
		void	executePresidential() const;
		void	execute(Bureaucrat const & executor) const;	
};

#endif