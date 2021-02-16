/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 15:06:48 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 12:46:58 by tclaudin         ###   ########.fr       */
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
