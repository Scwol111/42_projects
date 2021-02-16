/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pony.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 15:14:31 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 15:37:25 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>

class Pony
{
private:
	std::string _name;
	bool _danger_for_party;
	int	_money;
public:
	Pony();
	~Pony();
	void ChangeLoyality();
	void NationalizeMoney();
};
