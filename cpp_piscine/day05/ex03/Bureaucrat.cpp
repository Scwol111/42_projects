/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:48 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:20:39 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("common bureaucrat"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name): _name(name), _grade(150)
{
}

Bureaucrat::~Bureaucrat()
{
}

std::string const &Bureaucrat::getName() const
{
	return _name;
}

int Bureaucrat::getGrade() const
{
	return _grade;
}

void Bureaucrat::incGrade()
{
	if (_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	_grade--;
}

void Bureaucrat::decGrade()
{
	if (_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	_grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signs " << form.getName() << std::endl;
	}
	catch(const Form::FormAlreadySigned& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because form already signed" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because grade too low" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot sign " << form.getName() << " because unknown reason" << std::endl;
	}
	
}

void Bureaucrat::executeForm(Form const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(const Form::FormNotSigned &e)
	{
		std::cerr << _name << " cannot execute " << form.getName() << " because form not signed" << std::endl;
	}
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << _name << " cannot execute " << form.getName() << " because grade too low" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << _name << " cannot execute " << form.getName() << " because unknown reason" << std::endl;
		std::cerr << e.what() << std::endl;
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat: exception: too high grade";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat: exception: too low grade";
}

std::ostream &operator << (std::ostream &out, Bureaucrat &tmp)
{
	out << tmp.getName() << ", bureaucrat grade " << tmp.getGrade() << std::endl;
	return out;
}
