/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:09 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:52:52 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Victim.hpp"

Victim::Victim(const std::string &name): _name(name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::Victim(const Victim &copy): _name(copy._name)
{
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

Victim::~Victim()
{
	std::cout << "Victim " << _name << " just died for no apparent reason!" << std::endl;
}

void Victim::operator = (const Victim &copy)
{
	_name = copy._name;
	std::cout << "Some random victim called " << _name << " just appeared!" << std::endl;
}

void Victim::Introduce()
{
	std::cout << "I'm " << _name << " and I like otters!" << std::endl;
}

std::string Victim::GetName()
{
	return _name;
}

void Victim::getPolymorphed() const
{
	std::cout << _name << " has been turned into a cute little sheep!" << std::endl;
}

std::ostream& operator << (std::ostream &out, Victim &copy)
{
	std::cout << "I'm " << copy.GetName() << " and I like otters!" << std::endl;
	return out;
}
