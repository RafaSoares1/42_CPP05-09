/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emsoares <emsoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:57:05 by emsoares          #+#    #+#             */
/*   Updated: 2023/11/21 15:01:25 by emsoares         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm & src);
		RobotomyRequestForm &operator=(RobotomyRequestForm const& obj);
		~RobotomyRequestForm();
		RobotomyRequestForm(std::string target);
		std::string getTarget();
		void	executeRobotomy() const;
		void	execute(Bureaucrat const & executor) const;
};

#endif