/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:55:04 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 20:03:24 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

ScavTrap::ScavTrap(std::string const &name)
{
	_HP = 100;
	_EP = 50;
	_lvl = 1;
	_maxHP = 100;
	_maxEP = 50;
	_meleeDamage = 20;
	_rangeDamage = 15;
	_armor = 3;
	_name = "SC4V-TP " + name;
	std::cout << "I'm born and my name is " << name << ". What is my Destiny2?" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy)
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

void	ScavTrap::operator=(const ScavTrap &copy)
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

ScavTrap::~ScavTrap()
{
	std::cout << "Oh shit I pressed at self destruct button. Bye...\t\tBAM" << std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeDamage << " points of damage!" << std::endl;
}

void	ScavTrap::rangedAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at range, causing " << _rangeDamage << " points of damage!" << std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
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

void	ScavTrap::challengeNewcomer(std::string const &target)
{
	const int max_hi = 5;
	const int max_ch = 10;
	std::string welcome[max_hi] = {"LEAVE ME ALONE THEIF...\tOh it's you, ", "Welcome, ", "Hello my friend, ", "Greatings, ", "New challange for newcomer "};
	std::string challenge[max_ch] = {"Please find some of my bolts", "Bolts, bolts, bolts. I NEED MORE OF BOLTS. Find them", "I need a button cover for my self destruct button. Go and dont't return without it",
	"Let's get this party started! You'll prepare it for me", "Today is my birthday and you'll prepare my party", "I have an IDEA! You take some bullshit from bandits and bring it to me", "Run 40 kilometers for 10 credits",
	"See this ten-story building? Jump from the top and I'll give you some credits", "Kill those aborigens. KILL THEM ALL", "I've build some sanatorium at north. Please bring some person there"};

	int idx = std::rand() % max_hi;

	std::cout << welcome[idx] << target << std::endl;
	idx = std::rand() % max_ch;
	std::cout << challenge[idx] << std::endl;

}
