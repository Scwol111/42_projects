/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:25:36 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 16:06:56 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class AWeapon
{
protected:
	std::string _name;
	int _APcost;
	int _damage;

public:
	AWeapon();
	AWeapon(std::string const &, int, int);
	AWeapon(const AWeapon &);
	virtual ~AWeapon();
	void operator = (const AWeapon &);
	virtual std::string const &getName() const;
	int getAPCost() const;
	int getDamage() const;
	virtual void attack() const = 0;
};


