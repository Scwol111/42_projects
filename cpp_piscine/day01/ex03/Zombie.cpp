/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:37:03 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 19:35:10 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie()
{
	_name = "ZombieUnit" + std::to_string(std::rand() % 1000);
	_type = "Unit Of Random";
}

Zombie::Zombie(std::string name, std::string type): _name(name), _type(type)
{
}

Zombie::~Zombie()
{
	std::cout << '<' + _name + '(' + _type + ")> destroyed" << std::endl;
}

void	Zombie::announce()
{
	std::cout << '<' + _name + '(' + _type + ")> Braiiiiiiinnnssss...              Mmmmmmm, chhhickennnnnnn..." << std::endl;
}
