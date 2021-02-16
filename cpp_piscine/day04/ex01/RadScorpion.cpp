/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:28:11 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 14:33:22 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion(): Enemy(80, "RadScorpion")
{
	std::cout <<  "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(const RadScorpion &copy): Enemy(copy)
{
	std::cout <<  "* click click click *" << std::endl;
}

RadScorpion::~RadScorpion()
{
	std::cout <<  "* SPROTCH *" << std::endl;
}

void RadScorpion::operator=(const RadScorpion &copy)
{
	_HP = copy._HP;
	_type = copy._type;
	std::cout <<  "* click click click *" << std::endl;
}
