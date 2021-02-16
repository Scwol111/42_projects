/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:26 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 17:26:56 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

FragTrap::FragTrap()
{
	_HP = 100;
	_EP = 100;
	_lvl = 1;
	_maxHP = 100;
	_maxEP = 100;
	_meleeDamage = 30;
	_rangeDamage = 20;
	_armor = 5;
	_name = "FR4G-TP ";
	std::cout << "Hello world!!! " + _name + " ready for duty\t" + "\tStop, why I'm in Russia?\tSOMEONE, PLEASE, TAKE ME OUT OF HERE!!!" << std::endl;
}

FragTrap::FragTrap(std::string const &name)
{
	_HP = 100;
	_EP = 100;
	_lvl = 1;
	_maxHP = 100;
	_maxEP = 100;
	_meleeDamage = 30;
	_rangeDamage = 20;
	_armor = 5;
	_name = "FR4G-TP " + name;
	std::cout << "Hello world!!! " + name + " ready for duty\t" + "\tStop, why I'm in Russia?\tSOMEONE, PLEASE, TAKE ME OUT OF HERE!!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy)
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

void	FragTrap::operator=(const FragTrap &copy)
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

FragTrap::~FragTrap()
{
	std::cout << _name << ": I see...\tonly darkness...\tbefore me..." << std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at melee, causing " << _meleeDamage << " points of damage!" << std::endl;
}

void	FragTrap::rangedAttack(std::string const & target)
{
	_lvl++;
	std::cout << _name << " attacks " << target << " at range, causing " << _rangeDamage << " points of damage!" << std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
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

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	int idx;
	const int melee_max = 10;
	const int range_max = 10;
	std::string melee[melee_max] = {"Yeehaw!", "Take that!", "RUN FOR YOUR LIIIIIVES!!!", "Step right up, to the Bulletnator 9000!",
	"Can't touch this!", "Is it dead? Can, can I open my eyes now?", "Don't tell me that wasn't awesome!", "Ha ha ha! Suck it!", "Eat bomb, baddie!", "If I'll do it you take me out of Russia?"};
	std::string range[range_max] = {"If only my chassis... weren't made of recycled human body parts! Wahahaha!", "Extra ouch!", "Meatsplosion!", "F to the R to the 4 to the G to the WHAAT!",
	"Square the I, carry the 1... YES!", "It's happening... it's happening!", "You versus me! Me versus you! Either way!", "Dance battle! Or, you know... regular battle.", "I'm so sexy!", "If I'll do it you take me out of Russia?"};

	if (_EP >= 25)
	{
		_EP -= 25;
		if ((std::rand() & 0x1) == 1)
		{
			idx = std::rand() % melee_max;
			std::cout << melee[idx] << std::endl;
			meleeAttack(target);
		}
		else
		{
			idx = std::rand() % range_max;
			std::cout << range[idx] << std::endl;
			rangedAttack(target);
		}
	}
	else
	{
		std::cout << "I don't have enough energy, so I'll just sit here" << std::endl;
		std::cout << "Tu tu tu tutu tu tu tu...\tBoring...\tCall me later, I'll be at the bar" << std::endl;
	}
}
