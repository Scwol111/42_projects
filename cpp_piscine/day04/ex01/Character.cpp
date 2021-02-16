/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:33:58 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 16:09:19 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character():  _maxAP(40), _name("Unknown character"), _AP(_maxAP), _weapon(NULL)
{
}

Character::Character(const Character &copy): _maxAP(40), _name(copy._name), _AP(copy._AP), _weapon(copy._weapon)
{
}

Character::Character(const std::string &name): _maxAP(40), _name(name), _AP(_maxAP), _weapon()
{
}

Character::~Character()
{
	std::cout << "This world is too cruel" << std::endl;
}

void Character::operator=(const Character &copy)
{
	_name = copy._name;
	_AP = copy._AP;
	_weapon = copy._weapon;
}

void Character::recoverAP()
{
	if (_AP + 10 > _maxAP)
		_AP = _maxAP;
	else
		_AP += 10;
}

void Character::equip(AWeapon *weapon)
{
	_weapon = weapon;
}

void Character::attack(Enemy *enemy)
{
	if (_AP >= _weapon->getAPCost())
	{
		_AP -= _weapon->getAPCost();
		std::cout << _name << " attacks " << enemy->getType() << " with a " << _weapon->getName() << std::endl;
		_weapon->attack();
		enemy->takeDamage(_weapon->getDamage());
		if (enemy->getHP() == 0)
			delete enemy;
	}
	else
		std::cout << "Not enough AP to do that" << std::endl;
}

int Character::getAP() const
{
	return _AP;
}

const AWeapon *Character::getWeapon() const
{
	return _weapon;
}

std::string const &Character::getName() const
{
	return _name;
}

std::ostream &operator << (std::ostream &out, const Character &ch)
{
	out << ch.getName() << " has " << ch.getAP() << " AP and";
	if (ch.getWeapon() == NULL)
		out << " is unarmed" << std::endl;
	else
		out << " wields a " << ch.getWeapon()->getName() << std::endl;
	return out;
}
