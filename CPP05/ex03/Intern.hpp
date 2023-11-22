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
		AForm *makeForm(std::string name, std::string target);
};


#endif