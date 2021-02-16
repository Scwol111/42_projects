/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:40:59 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 16:23:57 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	_idea = "Nice jacket";
	
}

Brain::~Brain()
{
}

std::string	Brain::identify()
{
	std::string _base = "0123456789ABCDEF";
	std::string res;

	long poi = (unsigned long)this;
	for (; poi > 0; poi >>= 4)
		res = _base[poi & 0xF] + res;
	res = "0x" + res;
	return res;
}
