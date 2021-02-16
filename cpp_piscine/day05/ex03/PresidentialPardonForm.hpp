/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:43:14 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 18:46:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form
{
public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string const &);
	~PresidentialPardonForm();
	virtual void execute(Bureaucrat const &) const;
};
