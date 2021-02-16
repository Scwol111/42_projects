/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:40:21 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:21:27 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(): _xp(0)
{
}

AMateria::AMateria(std::string const &type): _type(type), _xp(0)
{
}

AMateria::~AMateria()
{
}

void AMateria::use(ICharacter& target)
{
	_xp += 10;
	std::cout << "* casting " << _type << " spell to " << target.getName() << " *" << std::endl;
}

std::string const &AMateria::getType() const
{
	return _type;
}

unsigned int AMateria::getXP() const
{
	return _xp;
}
