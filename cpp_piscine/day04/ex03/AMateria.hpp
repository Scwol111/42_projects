/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 12:40:23 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:50:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
class AMateria;
#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;
	unsigned int _xp;

public:
	AMateria();
	AMateria(std::string const &);
	virtual ~AMateria();
	std::string const &getType() const;
	unsigned int getXP() const;
	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter &) = 0;
};
