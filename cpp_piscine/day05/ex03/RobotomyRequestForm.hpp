/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:09:29 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:47:06 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include "Form.hpp"

class RobotomyRequestForm: public Form
{
public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string const &);
	~RobotomyRequestForm();
	virtual void execute(Bureaucrat const &) const;
	class RobotomyFailure: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};	
};