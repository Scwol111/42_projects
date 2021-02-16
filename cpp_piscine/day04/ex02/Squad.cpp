/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:30 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 15:00:31 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Squad.hpp"

Squad::Squad(): _buff(5), _count(0), _max(_buff)
{
	_squad = new ISpaceMarine*[_max];
}

Squad::Squad(const ISquad *copy): _buff(5), _count(copy->getCount()), _max(_count)
{
	_squad = new ISpaceMarine*[_max];
	for (int i = 0; i < _count; i++)
		_squad[i] = copy->getUnit(i)->clone();
}

Squad::Squad(const ISquad &copy): _buff(5), _count(copy.getCount()), _max(_count)
{
	_squad = new ISpaceMarine*[_max];
	for (int i = 0; i < _count; i++)
		_squad[i] = copy.getUnit(i)->clone();
}

Squad::~Squad()
{
	for (int i = 0; i < _count; i++)
		delete _squad[i];
	delete _squad;
}

int	Squad::getCount() const
{
	return _count;
}

ISpaceMarine* Squad::getUnit(int num) const
{
	if (num >= 0 && num <= _count)
		return _squad[num];
	std::cout << "This unit isn't in our army" << std::endl;
	return NULL;
}

int Squad::push(ISpaceMarine *unit)
{
	if (_count + 1 > _max)
	{
		_max += _buff;
		ISpaceMarine **_new = new ISpaceMarine*[_max];
		for (int i = 0; i < _count; i++)
			_new[i] = _squad[i];
		delete _squad;
		_squad = _new;
	}
	if (unit)
		_squad[_count++] = unit;
	return _count;
}

void Squad::operator=(const Squad &copy)
{
	_squad = new ISpaceMarine*[_max];
	for (int i = 0; i < _count; i++)
		_squad[i] = copy.getUnit(i)->clone();
}
