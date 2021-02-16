/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:00:58 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 13:06:03 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(): AMateria("cure")
{
}

Cure::~Cure()
{
}

AMateria *Cure::clone() const
{
	return new Cure;
}

void Cure::use(ICharacter &user)
{
	_xp += 10;
	std::cout << "* heals " << user.getName() << "’s wounds *" << std::endl;
}
