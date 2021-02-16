/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:19:28 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:59:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SuperMutant.hpp"

SuperMutant::SuperMutant(): Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::SuperMutant(const SuperMutant &copy): Enemy(copy)
{
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh..." << std::endl;
}

void SuperMutant::operator=(const SuperMutant &copy)
{
	_HP = copy._HP;
	_type = copy._type;
	std::cout << "Gaaah. Me want smash heads!" << std::endl;
}

void SuperMutant::takeDamage(int n)
{
	if (n > 3)
		n -= 3;
	else
		n = 0;
	if (_HP > 0)
	{
		_HP -= n;
		if (_HP < 0)
			_HP = 0;
	}
}
