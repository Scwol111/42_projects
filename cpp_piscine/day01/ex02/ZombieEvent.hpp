/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieEvent.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/28 15:59:46 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 18:17:25 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Zombie.hpp"

class ZombieEvent
{
private:
	std::string _type;
	
public:
	ZombieEvent();
	~ZombieEvent();
	void setZombieType(std::string type);
	Zombie* newZombie(std::string name);
};

