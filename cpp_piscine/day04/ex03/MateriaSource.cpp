/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:45:16 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:08:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	_arr = new AMateria*[4];
	for (int i = 0; i < 4; i++)
		_arr[i] = NULL;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
		if (_arr[i])
			delete _arr[i];
	delete _arr;
}

void MateriaSource::learnMateria(AMateria *mat)
{
	for (int i = 0; i < 4; i++)
		if (!_arr[i])
		{
			_arr[i] = mat;
			break;
		}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_arr[i] && _arr[i]->getType() == type)
			return _arr[i]->clone();
	}
	return NULL;
}
