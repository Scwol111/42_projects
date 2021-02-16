/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:24 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 18:51:58 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>

class FragTrap
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
	FragTrap(std::string const &name);
	FragTrap(const FragTrap &copy);
	void operator = (const FragTrap &copy);
	~FragTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
	void beRecharged(unsigned int amount);
	void vaulthunter_dot_exe(std::string const & target);
};
