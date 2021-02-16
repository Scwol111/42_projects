/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:51:02 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 16:37:34 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Form;
#include "Bureaucrat.hpp"

class Form
{
private:
	std::string	_name;
	bool		_signed;
	int			_gradeSign;
	int			_gradeExec;
public:
	Form();
	Form(std::string const &, int, int);
	~Form();
	class GradeTooHighException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	class FormAlreadySigned: public std::exception {
		public:
			virtual const char* what() const throw();
	};
	void beSigned(const Bureaucrat &);
	std::string const &getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
};

std::ostream &operator << (std::ostream &, Form &);
