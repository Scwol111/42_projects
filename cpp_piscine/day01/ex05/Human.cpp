/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Human.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 12:43:02 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/29 16:24:09 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Human.hpp"
#include <iostream>

Human::Human()
{
}

Human::~Human()
{
}

std::string	Human::identify()
{
	std::string _base = "0123456789ABCDEF";
	std::string res;

	long poi = (unsigned long)&_brain;
	for (; poi > 0; poi >>= 4)
		res = _base[poi & 0xF] + res;
	res = "0x" + res;

	return res;
}

Brain &Human::getBrain()
{
	return _brain;
}