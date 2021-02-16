/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:00:50 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 16:07:08 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AWeapon.hpp"

class PowerFist: public AWeapon
{
public:
	PowerFist();
	PowerFist(const PowerFist &copy);
	virtual ~PowerFist();
	void operator = (const PowerFist &copy);
	virtual void attack() const;
};
