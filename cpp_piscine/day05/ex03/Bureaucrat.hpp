/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:46 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 16:52:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

class Bureaucrat;
#include "Form.hpp"

class Bureaucrat
{
private:
	std::string _name;
	int _grade;
	
public:
	Bureaucrat();
	Bureaucrat(std::string const &name);
	~Bureaucrat();
	class GradeTooHighException: public std::exception {
		virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		virtual const char* what() const throw();
	};
	std::string const& getName() const;
	int getGrade() const;
	void incGrade();
	void decGrade();
	void signForm(Form &);
	void executeForm(Form const &);
};

std::ostream &operator << (std::ostream &, Bureaucrat &);
