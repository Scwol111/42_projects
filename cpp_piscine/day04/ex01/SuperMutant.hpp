/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:19:29 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:55:41 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Enemy.hpp"
#include <iostream>

class SuperMutant: public Enemy
{
public:
	SuperMutant();
	SuperMutant(const SuperMutant &);
	virtual ~SuperMutant();
	void operator = (const SuperMutant &);
	virtual void takeDamage(int);
};


