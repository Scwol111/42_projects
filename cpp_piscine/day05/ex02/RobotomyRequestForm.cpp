/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:10:04 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 17:26:41 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("Robotomy Request Form", 45, 72)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << "* RRRRRRRRR VZVZVVZVZVVZVZ GRGRGGRGRGRRGG *" << std::endl;
	if (std::rand() & 0x1)
		std::cout << executor.getName() << " has been robotomized successfully" << std::endl;
	else
		throw RobotomyRequestForm::RobotomyFailure();
}

const char* RobotomyRequestForm::RobotomyFailure::what() const throw()
{
	return "Robotomy Request Form: exception: robotomized failured";
}
