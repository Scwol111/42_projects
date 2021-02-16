/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:23:52 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/07 15:42:29 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class ClapTrap
{
protected:
	unsigned int	_HP;
	unsigned int	_EP;
	unsigned int 	_lvl;
	unsigned int	_maxHP;
	unsigned int	_maxEP;
	unsigned int	_meleeDamage;
	unsigned int	_rangeDamage;
	unsigned int	_armor;
	std::string		_name;

public:
	ClapTrap(std::string name);
	ClapTrap();
	~ClapTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void beRecharged(unsigned int amount);
	std::string GetName();
	unsigned int GetMeleeDamage();
	unsigned int GetRangeDamage();
};
