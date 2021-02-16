/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:07:30 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:55:11 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Enemy
{
protected:
	int _HP;
	std::string _type;
public:
	Enemy(int hp, std::string const & type);
	Enemy(const Enemy &copy);
	Enemy();
	virtual ~Enemy();
	void operator = (const Enemy &copy);
	std::string const &getType() const;
	int getHP() const;
	virtual void takeDamage(int);
};
