/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:23:50 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 17:32:39 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
{
	_HP = 1000;
	_EP = 1000;
	_lvl = 1000;
	_maxHP = 1000;
	_maxEP = 1000;
	_meleeDamage = 1000;
	_rangeDamage = 1000;
	_armor = 0;
	std::cout << "ClapTrap unit" << _name << " created" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name("CL4P-TP " + name)
{
	_HP = 1000;
	_EP = 1000;
	_lvl = 1000;
	_maxHP = 1000;
	_maxEP = 1000;
	_meleeDamage = 1000;
	_rangeDamage = 1000;
	_armor = 0;
	std::cout << "ClapTrap unit " << name << " created" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap unit " << _name << " destroyed" << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_HP < _maxHP)
	{
		if (_HP + amount > _maxHP)
		{
			_HP = _maxHP;
			std::cout << _name << " fully repaired at " << _maxHP - amount << " points" << std::endl;
		}
		else
		{
			std::cout << _name << " repaired at " << amount << " points" << std::endl;
			_HP += amount;
		}
	}
	else
	{
		std::cout << _name << " already repaired" << std::endl;
	}	
}

void	ClapTrap::beRecharged(unsigned int amount)
{
	if (_EP < _maxEP)
	{
		if (_EP + amount > _maxEP)
		{
			_EP = _maxEP;
			std::cout << _name << " fully recharged at " << _maxEP - amount << " points" << std::endl;
		}
		else
		{
			std::cout << _name << " recharged at " << amount << " points" << std::endl;
			_EP += amount;
		}
	}
	else
	{
		std::cout << _name << " already recharged" << std::endl;
	}	
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeDamage << " points of damage!" << std::endl;
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at range, causing " << _rangeDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
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

std::string ClapTrap::GetName()
{
	return _name;
}

unsigned int ClapTrap::GetMeleeDamage()
{
	return _meleeDamage;
}

unsigned int ClapTrap::GetRangeDamage()
{
	return _rangeDamage;
}
