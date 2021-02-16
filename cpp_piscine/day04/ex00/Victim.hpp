/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:11 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 12:11:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Victim
{
protected:
	std::string _name;
public:
	Victim(const std::string &name);
	Victim(const Victim &copy);
	virtual ~Victim();
	void operator = (const Victim &copy);
	void Introduce();
	std::string GetName();
	virtual void getPolymorphed() const;
};

std::ostream& operator << (std::ostream &out, Victim &copy);
