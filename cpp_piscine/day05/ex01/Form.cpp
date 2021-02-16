/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:51:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 16:37:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("common paper"), _gradeSign(150), _gradeExec(150)
{
	_signed = false;
}

Form::Form(std::string const &name, int exec, int sign): _name(name), _gradeSign(sign), _gradeExec(exec)
{
	_signed = false;
	if (_gradeExec > 150 || _gradeSign > 150)
		throw Form::GradeTooLowException();
	if (_gradeExec < 1 || _gradeSign < 1)
		throw Form::GradeTooHighException();
}

Form::~Form()
{
}

void Form::beSigned(const Bureaucrat& user)
{
	if (_signed)
		throw Form::FormAlreadySigned();
	if (user.getGrade() > _gradeSign)
		throw Form::GradeTooLowException();
	_signed = true;
}

std::string const &Form::getName() const
{
	return _name;
}

int Form::getExecGrade() const
{
	return _gradeExec;
}

int Form::getSignGrade() const
{
	return _gradeSign;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form: exception: too high grade";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form: exception: too low grade";
}

const char* Form::FormAlreadySigned::what() const throw()
{
	return "Form: exception: form already signed";
}

std::ostream &operator << (std::ostream &out, Form &form)
{
	out << "Form " << form.getName() << " can be signed with " << form.getSignGrade() << " grade and executed with " << form.getExecGrade() << " grade" << std::endl;
	return out;
}
