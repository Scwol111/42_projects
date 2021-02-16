/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:25:34 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:55:14 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AWeapon.hpp"

AWeapon::AWeapon(): _name("unarmed"), _APcost(1), _damage(4)
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage): _name(name), _APcost(apcost), _damage(damage)
{
}

AWeapon::AWeapon(const AWeapon &copy): _name(copy._name), _APcost(copy._APcost), _damage(copy._damage)
{
}

AWeapon::~AWeapon()
{
}

void AWeapon::operator=(const AWeapon &copy)
{
	_name = copy._name;
	_APcost = copy._APcost;
	_damage = copy._damage;
}

std::string const &AWeapon::getName() const
{
	return _name;
}

int AWeapon::getAPCost() const
{
	return _APcost;
}

int AWeapon::getDamage() const
{
	return _damage;
}
