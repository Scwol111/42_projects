/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 17:29:24 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 20:02:40 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
public:
	FragTrap(std::string const &name);
	FragTrap(const FragTrap &copy);
	~FragTrap();
	void rangedAttack(std::string const & target);
	void meleeAttack(std::string const & target);
	void takeDamage(unsigned int amount);
	void operator = (const FragTrap &copy);
	void vaulthunter_dot_exe(std::string const & target);
};
