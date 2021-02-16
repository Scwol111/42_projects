/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 14:55:06 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 18:54:46 by tclaudin         ###   ########.fr       */
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
	void challengeNewcomer(std::string const &target);
};

