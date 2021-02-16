/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 17:08:41 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 13:40:48 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "ZombieEvent.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

void randomChump()
{
	std::srand(std::time(NULL));
	Zombie zomb("ZombieUnit" + std::to_string(std::rand() % 100), "Future Unit");
	Zombie *rzomb = new Zombie("ZombieUnit" + std::to_string(std::rand() % 100), "Nazi");
	zomb.announce();
	rzomb->announce();
	delete rzomb;
}

int main()
{
	Zombie zomb("Hello", "World");
	zomb.announce();

	ZombieEvent event;
	event.setZombieType("Blade Runner");

	Zombie *ZFE = event.newZombie("Ivan");
	ZFE->announce();
	delete ZFE;

	randomChump();

	return 0;
}
