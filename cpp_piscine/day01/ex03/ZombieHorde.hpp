/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 18:35:27 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 19:36:47 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Zombie.hpp"
#include <iostream>

class ZombieHorde
{
private:
	Zombie *_horde;
	const int _max;

public:
	ZombieHorde(int n);
	~ZombieHorde();
	void SayHello();
};

