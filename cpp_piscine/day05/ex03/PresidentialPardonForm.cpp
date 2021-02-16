/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:42:06 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:48:11 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("Presidential Pardon Form", 5, 25)
{
}

PresidentialPardonForm::PresidentialPardonForm(std::string const &target): Form("Presidential Pardon Form", 5, 25, target)
{
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	Form::execute(executor);
	std::cout << executor.getName() << " has been pardoned by Zafod Beeblebrox" << std::endl;
}
