/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 18:28:11 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 19:46:42 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
}

Intern::~Intern()
{
}

Form *Intern::generatePresident(std::string const &target)
{
	return new PresidentialPardonForm(target);
}

Form *Intern::generateRobotomy(std::string const &target)
{
	return new RobotomyRequestForm(target);
}

Form *Intern::generateShrubbery(std::string const &target)
{
	return new ShrubberyCreationForm(target);
}

Form *Intern::makeForm(std::string const &form, std::string const &target)
{
	Form* (*_hosts[_maxGenera])(std::string const &) = {generatePresident, generateRobotomy, generateShrubbery};
	std::string _knowns[_maxKnowns] = {"PresidentialPardonForm", "Presidential Pardon Form", "Presidential Pardon", "Presidential pardon", "presidential Pardon", "presidential pardon",
	"RobotomyRequestForm", "Robotomy Request Form", "Robotomy Request", "Robotomy request", "robotomy Request" , "robotomy request",
	"ShrubberyCreationForm", "Shrubbery Creation Form", "Shrubbery Creation", "shrubbery Creation", "Shrubbery creation", "shrubbery creation"};
	for (int i = 0; i < _maxKnowns; i++)
	{
		if (_knowns[i] == form)
		{
			int k = i / (_maxKnowns / _maxGenera);
			std::cout << "Intern creates " << _knowns[k * (_maxKnowns / _maxGenera) + 1] << std::endl;
			return _hosts[k](target);
		}
	}
	throw InternUnknownFormException();
}

const char* Intern::InternUnknownFormException::what() const throw()
{
	return "Intern: exception: Unknown form";
}