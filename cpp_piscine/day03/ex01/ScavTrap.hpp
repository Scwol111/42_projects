/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:55:06 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 18:53:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class ScavTrap
{
private:
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
	ScavTrap(std::string const &name);
	ScavTrap(const ScavTrap &copy);
	void operator=(const ScavTrap &copy);
	~ScavTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void beRecharged(unsigned int amount);
	void challengeNewcomer(std::string const &target);
};
