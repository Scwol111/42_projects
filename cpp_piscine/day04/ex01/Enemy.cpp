/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:07:28 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:55:45 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy(): _HP(50), _type("Communist raider")
{
	std::cout << "Communism come to this world" << std::endl;
}

Enemy::Enemy(int hp, std::string const &type): _HP(hp), _type(type)
{
}

Enemy::Enemy(const Enemy &copy): _HP(copy._HP), _type(copy._type)
{
}

Enemy::~Enemy()
{
}

void Enemy::operator=(const Enemy &copy)
{
	_HP = copy._HP;
	_type = copy._type;
}

std::string const &Enemy::getType() const
{
	return _type;
}

int Enemy::getHP() const
{
	return _HP;
}

void Enemy::takeDamage(int n)
{
	if (_HP > 0)
	{
		_HP -= n;
		if (_HP < 0)
			_HP = 0;
	}
}
