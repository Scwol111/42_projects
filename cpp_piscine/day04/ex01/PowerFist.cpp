/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:00:49 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:57:00 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist(): AWeapon("Power Fist", 8, 50)
{
}

PowerFist::PowerFist(const PowerFist &copy): AWeapon(copy)
{
}

PowerFist::~PowerFist()
{
}

void PowerFist::operator=(const PowerFist &copy)
{
	_name = copy._name;
	_APcost = copy._APcost;
	_damage = copy._damage;
}

void PowerFist::attack() const
{
	std::cout <<  "* pschhh... SBAM! *" << std::endl;
}
