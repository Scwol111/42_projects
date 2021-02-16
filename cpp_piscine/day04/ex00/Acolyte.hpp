/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Acolyte.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 13:05:58 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/12 12:43:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Peon.hpp"

class Acolyte: public Peon
{
public:
	Acolyte(const std::string &name);
	Acolyte(const Acolyte &copy);
	virtual ~Acolyte();
	void operator = (const Acolyte &copy);
	void Introduce();
	//virtual void getPolymorphed() const;
};
