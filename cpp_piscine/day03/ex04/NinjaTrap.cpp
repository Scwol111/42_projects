/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NinjaTrap.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:58:35 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 17:27:00 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "NinjaTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <cstdlib>

NinjaTrap::NinjaTrap()
{
	_HP = 60;
	_EP = 120;
	_lvl = 1;
	_maxHP = 60;
	_maxEP = 120;
	_meleeDamage = 60;
	_rangeDamage = 5;
	_armor = 0;
	_name = "IN4C-TP ";
	std::cout << "YOU ARE NOT PREPARED I'M " << _name << " AND I'LL DESTROY YOU" << std::endl;
}

NinjaTrap::NinjaTrap(const std::string name)
{
	_HP = 60;
	_EP = 120;
	_lvl = 1;
	_maxHP = 60;
	_maxEP = 120;
	_meleeDamage = 60;
	_rangeDamage = 5;
	_armor = 0;
	_name = "IN4C-TP " + name;
	std::cout << "YOU ARE NOT PREPARED I'M " << name << " AND I'LL DESTROY YOU" << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "The hunter can't live without hunting. And you, nothing without me..." << std::endl;
}

NinjaTrap::NinjaTrap(const NinjaTrap &copy)
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
	std::cout << _name << " Unit cloned" << std::endl;
}

void	NinjaTrap::operator=(const NinjaTrap &copy)
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

void	NinjaTrap::meleeAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeDamage << " points of damage!" << std::endl;
}

void	NinjaTrap::rangedAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at range, causing " << _rangeDamage << " points of damage!" << std::endl;
}

void	NinjaTrap::takeDamage(unsigned int amount)
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

void	NinjaTrap::ninjaShoebox(FragTrap &trap)
{
	if (_EP >= 50)
	{
		_EP -= 50;
		if (std::rand() % 2 == 1)
		{
			std::cout << "Kung-fu stronger than guns. Ha ha" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "The bullet is a fool, and the bayonet is good" << std::endl;
				meleeAttack(trap.GetName());
				trap.takeDamage(_meleeDamage);
			}
			else
			{
				std::cout << "I throw bullets in you. You'll die soon" << std::endl;
				rangedAttack(trap.GetName());
				trap.takeDamage(_rangeDamage);
			}
		}
		else
		{
			std::cout << "So dishonest you haven't even tried stealth" << std::endl;
			if (std::rand() % 2 == 1)
			{
				trap.meleeAttack(GetName());
				takeDamage(trap.GetMeleeDamage());
				std::cout << "You hit like a girl. Fie..." << std::endl;
			}
			else
			{
				std::cout << "I'm fast, but bullet faster. You win this battle" << std::endl;
				trap.rangedAttack(GetName());
				takeDamage(trap.GetRangeDamage());
			}
		}
	}
	else
		std::cout << "Not enough mana to do that" << std::endl;
}

void	NinjaTrap::ninjaShoebox(NinjaTrap &trap)
{
	if (_EP >= 50)
	{
		_EP -= 50;
		if (std::rand() % 2 == 1)
		{
			std::cout << "Ha ha my kung-fu is stronger than your kung-fu" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "Vzhuh and you are cut into small pieces" << std::endl;
				meleeAttack(trap.GetName());
				trap.takeDamage(_meleeDamage);
			}
			else
			{
				std::cout << "Put this apple on your head. Thanks" << std::endl;
				rangedAttack(trap.GetName());
				trap.takeDamage(_rangeDamage);
			}
		}
		else
		{
			std::cout << "You win, master. My life is in your hands" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "AAAAA just not in the face. just not in the face" << std::endl;
				trap.meleeAttack(GetName());
				takeDamage(trap.GetMeleeDamage());
			}
			else
			{
				std::cout << "If you accidentally hit me, then I will be very upset" << std::endl;
				trap.rangedAttack(GetName());
				takeDamage(trap.GetRangeDamage());
				std::cout << "AAAAAAAAAAAAAA IT'S HIRT" << std::endl;
			}
		}
	}
	else
		std::cout << "I...\tneed...\tsome...\trest..." << std::endl;
}

void	NinjaTrap::ninjaShoebox(ClapTrap &trap)
{
	if (_EP >= 50)
	{
		_EP -= 50;
		if (std::rand() % 2 == 1)
		{
			std::cout << "I don't know who you are, but I'll kill you" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "Where your head? I have no idea. Tell me and I'll give you fast death" << std::endl;
				meleeAttack(trap.GetName());
				trap.takeDamage(_meleeDamage);
			}
			else
			{
				std::cout << "It's scary to come to you. Please take these bullets and leave me alone" << std::endl;
				rangedAttack(trap.GetName());
				trap.takeDamage(_rangeDamage);
			}
		}
		else
		{
			std::cout << "No no no no no. Please don't come" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "Take my hand, but let me go, please\tplease" << std::endl;
				trap.meleeAttack(GetName());
				takeDamage(trap.GetMeleeDamage());
			}
			else
			{
				std::cout << _name << " try to run from the battle" << std::endl;
				trap.rangedAttack(GetName());
				takeDamage(trap.GetRangeDamage());
				std::cout << "Hit in back is very dishonorable" << std::endl;
			}
		}
	}
	else
		std::cout << "I'll kill you tomorrow, after long oil bath" << std::endl;
}

void	NinjaTrap::ninjaShoebox(ScavTrap &trap)
{
	if (_EP >= 50)
	{
		_EP -= 50;
		if (std::rand() % 2 == 1)
		{
			std::cout << "TODAY YOU WILL LOSE MANY OF YOUR BOLTS HA HA HA HA" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "Plus bolts, minus hand" << std::endl;
				meleeAttack(trap.GetName());
				trap.takeDamage(_meleeDamage);
			}
			else
			{
				std::cout << "I've forgot my bullets at home, but I have some heave books" << std::endl;
				rangedAttack(trap.GetName());
				trap.takeDamage(_rangeDamage);
			}
		}
		else
		{
			std::cout << "It's impossible. How can you beat me?" << std::endl;
			if (std::rand() % 2 == 1)
			{
				std::cout << "Noooooooooo. It's lie" << std::endl;
				trap.meleeAttack(GetName());
				takeDamage(trap.GetMeleeDamage());
			}
			else
			{
				std::cout << "Casting energy shield...\tPlease wait" << std::endl;
				trap.rangedAttack(GetName());
				takeDamage(trap.GetRangeDamage());
				std::cout << "Augh...\tI didn't have enough time to cast shield. It's dishonor" << std::endl;
			}
		}
	}
	else
		std::cout << "It's too easy for me... \tDo you have any battery?" << std::endl;
}
