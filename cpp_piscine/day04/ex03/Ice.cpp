/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:53:56 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 13:07:05 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(): AMateria("ice")
{
}

Ice::~Ice()
{
}

AMateria* Ice::clone() const
{
	return new Ice;
}

void Ice::use(ICharacter &user)
{
	_xp += 10;
	std::cout << "* shoots an ice bolt at " << user.getName() <<" *" << std::endl;
}
