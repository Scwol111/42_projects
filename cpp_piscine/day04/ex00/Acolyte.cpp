/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acolyte.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:06:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 12:43:57 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Acolyte.hpp"

Acolyte::Acolyte(const std::string &name): Peon(name)
{
	std::cout << "Thirsty to serve" << std::endl;
}

Acolyte::Acolyte(const Acolyte &copy):Peon(copy._name)
{
	std::cout << "Thirsty to serve" << std::endl;
}

Acolyte::~Acolyte()
{
	std::cout << "Death will consume everything" << std::endl;
}

void Acolyte::operator = (const Acolyte &copy)
{
	_name = copy._name;
	std::cout << "Thirsty to serve" << std::endl;
}

void Acolyte::Introduce()
{
	std::cout << _name << " want give his life for Ner-Zul" << std::endl;
}

// void Acolyte::getPolymorphed() const
// {
// 	std::cout << _name << " has turned into invisible shadow" << std::endl;
// }
