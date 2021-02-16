/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:46:03 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 14:02:36 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string str): _type(str)
{
}

Weapon::Weapon(): _type("Fists")
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string str)
{
	_type = str;
}

const std::string&	Weapon::getType()
{
	return _type;
}
