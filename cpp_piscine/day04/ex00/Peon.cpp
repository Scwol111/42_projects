/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:05 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 12:53:09 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Peon.hpp"

Peon::Peon(const std::string &name): Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(const Peon &copy): Victim(copy._name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

void Peon::operator = (const Peon &copy)
{
	_name = copy._name;
	std::cout << "Zog zog." << std::endl;
}

void Peon::getPolymorphed() const
{
	std::cout << _name << " has been turned into a pink pony!" << std::endl;
}
