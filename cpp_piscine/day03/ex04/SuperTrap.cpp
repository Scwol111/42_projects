/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 15:34:47 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 17:33:13 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperTrap.hpp"

SuperTrap::SuperTrap(std::string name): NinjaTrap(name), FragTrap(name)
{
	_HP = 100;
	_EP = 120;
	_lvl = 1;
	_maxHP = 100;
	_maxEP = 120;
	_meleeDamage = 60;
	_rangeDamage = 20;
	_armor = 5;
	_name = "SP3R-TP " + name;
	std::cout << "Tremble, mortals, and despair! Doom has come to this world! " << _name << " Has born" << std::endl;
}

SuperTrap::SuperTrap(const SuperTrap &copy)
{
	_HP = copy._HP;
	_EP = copy._EP;
	_lvl = copy._lvl;
	_maxHP = copy._maxHP;
	_maxEP = copy._maxEP;
	_meleeDamage = copy._meleeDamage;
	_rangeDamage = copy._rangeDamage;
	_armor = copy._armor;
	_name = copy._name;
	std::cout << _name << " Unit reported" << std::endl;
}

void	SuperTrap::operator=(const SuperTrap &copy)
{
	_HP = copy._HP;
	_EP = copy._EP;
	_lvl = copy._lvl;
	_maxHP = copy._maxHP;
	_maxEP = copy._maxEP;
	_meleeDamage = copy._meleeDamage;
	_rangeDamage = copy._rangeDamage;
	_armor = copy._armor;
	_name = copy._name;
	std::cout << "Now I'm " << _name << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "Our hero " << _name << " died" << std::endl;
}

void	SuperTrap::meleeAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeDamage << " points of damage!" << std::endl;
}

void	SuperTrap::rangedAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at range, causing " << _rangeDamage << " points of damage!" << std::endl;
}

void	SuperTrap::takeDamage(unsigned int amount)
{
	if (_HP - amount + _armor  > 0)
	{
		std::cout << _name << " taken " << amount - _armor << " damage." << std::endl;
		_HP -= amount + _armor;
	}
	else
	{
		std::cout << _name << " taken " << _HP << " damage." << std::endl;
		_HP = 0;
	}
}
