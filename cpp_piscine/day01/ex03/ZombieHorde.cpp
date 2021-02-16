/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:35:25 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 19:43:35 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ZombieHorde.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

ZombieHorde::ZombieHorde(int n) : _max(n)
{
	_horde = new Zombie[_max];
}

ZombieHorde::~ZombieHorde()
{
	delete [] _horde;
	std::cout << "Horde destroyed" << std::endl;
}

void	ZombieHorde::SayHello()
{
	for (int i = 0; i < _max; i++)
		_horde[i].announce();
}