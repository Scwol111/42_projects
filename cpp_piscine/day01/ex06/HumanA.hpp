/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 13:52:10 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 14:38:12 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
private:
	Weapon &_weapon;
	std::string _name;

public:
	HumanA(std::string name, Weapon &wp);
	~HumanA();
	void attack();
};
