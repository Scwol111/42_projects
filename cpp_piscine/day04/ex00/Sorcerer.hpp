/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 12:04:02 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 12:52:48 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Victim.hpp"

class Sorcerer
{
private:
	std::string _name;
	std::string _title;
public:
	Sorcerer(const std::string &name, const std::string &title);
	Sorcerer(const Sorcerer &copy);
	~Sorcerer();
	void operator = (const Sorcerer &copy);
	void Introduce();
	std::string GetName();
	std::string GetTitle();
	void polymorph(Victim const &) const;
};

std::ostream& operator<< (std::ostream &out, Sorcerer &s);
