/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:27:34 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 19:43:25 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
	static const int _maxKnowns = 18;
	static const int _maxGenera = 3;
	static Form *generatePresident(std::string const &);
	static Form *generateRobotomy(std::string const &);
	static Form *generateShrubbery(std::string const &);

public:
	Intern();
	~Intern();
	Form *makeForm(std::string const &, std::string const &);
	class InternUnknownFormException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};
