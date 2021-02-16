/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:07 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 12:11:19 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Victim.hpp"

class Peon: public Victim
{
public:
	Peon(const std::string &name);
	Peon(const Peon &copy);
	virtual ~Peon();
	void operator = (const Peon &copy);
	virtual void getPolymorphed() const;
};
