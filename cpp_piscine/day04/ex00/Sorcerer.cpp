/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:54:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer(const std::string &name, const std::string &title): _name(name), _title(title)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::Sorcerer(const Sorcerer &copy): _name(copy._name), _title(copy._title)
{
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

Sorcerer::~Sorcerer()
{
	std::cout << _name << ", " << _title << ", is dead. Consequences will never be the same!" << std::endl;
}

void Sorcerer::operator = (const Sorcerer &copy)
{
	_name = copy._name;
	_title = copy._title;
	std::cout << _name << ", " << _title << ", is born!" << std::endl;
}

void Sorcerer::Introduce()
{
	std::cout << "I am " << _name << ", " << _title << ", and I like ponies!" << std::endl;
}

std::string Sorcerer::GetName()
{
	return _name;
}

std::string Sorcerer::GetTitle()
{
	return _title;
}

void Sorcerer::polymorph(Victim const &victim) const
{
	victim.getPolymorphed();
}

std::ostream& operator<< (std::ostream &out, Sorcerer &s)
{
	std::cout << "I am " << s.GetName() << ", " << s.GetTitle() << ", and I like ponies!" << std::endl;
	return out;
}
