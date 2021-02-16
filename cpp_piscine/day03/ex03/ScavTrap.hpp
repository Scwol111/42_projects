/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:55:06 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 20:02:43 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

class ScavTrap: public ClapTrap
{
public:
	ScavTrap(std::string const &name);
	ScavTrap(const ScavTrap &copy);
	void operator=(const ScavTrap &copy);
	~ScavTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void challengeNewcomer(std::string const &target);
};

