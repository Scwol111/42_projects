/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:45:38 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:54:31 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(): AWeapon("Plasma Rifle", 5, 21)
{
}

PlasmaRifle::PlasmaRifle(const PlasmaRifle &copy): AWeapon(copy)
{
}

PlasmaRifle::~PlasmaRifle()
{
}

void PlasmaRifle::operator=(const PlasmaRifle &copy)
{
	_name = copy._name;
	_APcost = copy._APcost;
	_damage = copy._damage;
}

void PlasmaRifle::attack() const
{
	std::cout <<  "* piouuu piouuu piouuu *" << std::endl;
}
