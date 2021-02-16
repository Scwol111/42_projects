/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 13:07:15 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 14:50:14 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
private:
	std::string _name;
	AMateria **_arr;

public:
	Character(std::string const &);
	Character(const Character&);
	virtual ~Character();
	virtual std::string const & getName() const;
	virtual void equip(AMateria *m);
	virtual void unequip(int idx);
	virtual void use(int, ICharacter&);
};
