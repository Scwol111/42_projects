/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:07:18 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:16:20 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(std::string const &name): _name(name)
{
	_arr = new AMateria*[3];
	for (int i = 0; i < 3; i++)
		_arr[i] = NULL;
}

Character::Character(const Character &copy): _name(copy.getName())
{
	_arr = new AMateria*[3];
	for (int i = 0; i < 3; i++)
		// _arr[i] = copy._arr[i]->clone();
		_arr[i] = copy._arr[i];
}

Character::~Character()
{
	// for (int i = 0; i < 3; i++)
	// 	if (_arr[i])
	// 		delete _arr[i];
	delete _arr;
}

std::string const &Character::getName() const
{
	return _name;
}

void Character::use(int idx, ICharacter &user)
{
	if (idx >= 0 && idx < 3 && _arr[idx])
		_arr[idx]->use(user);
}

void Character::equip(AMateria *m)
{
	for (int i = 0; i < 3; i++)
		if (!_arr[i])
		{
			_arr[i] = m;
			break;
		}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 3)
		_arr[idx] = NULL;
}
