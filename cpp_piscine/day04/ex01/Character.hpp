/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:34:00 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:36:58 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AWeapon.hpp"
#include "Enemy.hpp"

class Character
{
private:
	const int _maxAP;
	std::string _name;
	int _AP;
	AWeapon *_weapon;

public:
	Character();
	Character(const Character &);
	Character(const std::string &);
	~Character();
	void operator = (const Character &);
	void recoverAP();
	void equip(AWeapon*);
	void attack(Enemy*);
	std::string const &getName() const;
	int getAP() const;
	const AWeapon *getWeapon() const;
};

std::ostream &operator << (std::ostream &, const Character &);
