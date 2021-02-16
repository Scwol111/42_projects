/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:14:29 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 15:19:47 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Pony.hpp"

Pony::Pony()
{
	_name = "PonyUnit" + std::to_string(std::rand() % 10000);
	std::cout << _name << " Reporting for duty" << std::endl;
	if (std::rand() % 2)
	{
		_danger_for_party = true;
		std::cout << "Warning this Pony is danger for our Party" << std::endl;
	}
	else
		_danger_for_party = false;
	_money = std::rand();
}

Pony::~Pony()
{
	std::cout << _name << " KIA. Glory to Equestria!!!" << std::endl;
}

void	Pony::ChangeLoyality()
{
	if (_danger_for_party)
	{
		_danger_for_party = false;
		std::cout << _name << " now loyaly for our Party" << std::endl;
	}
	else
	{
		_danger_for_party = true;
		std::cout << _name << " Warning, this Pony become danger for our Party" << std::endl;
	}
}

void	Pony::NationalizeMoney()
{
	if (_money > 0)
	{
		std::cout << _name << " Your money " << std::to_string(_money) << " was taken for our Motherland. You'll be rewarded soon" << std::endl;
		_money = 0;
	}
	else
		std::cout << _name << " Be happy. You're now you have 10 additional working hour. Glory to Equestria!!!" << std::endl;
}
