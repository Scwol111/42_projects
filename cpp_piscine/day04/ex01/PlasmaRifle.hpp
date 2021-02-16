/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:45:36 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 16:07:07 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AWeapon.hpp"

class PlasmaRifle: public AWeapon
{
public:
	PlasmaRifle();
	PlasmaRifle(const PlasmaRifle &copy);
	virtual ~PlasmaRifle();
	void operator = (const PlasmaRifle &copy);
	virtual void attack() const;
};


