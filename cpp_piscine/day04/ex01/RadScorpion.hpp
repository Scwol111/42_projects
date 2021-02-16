/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 14:28:10 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/09 15:55:42 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Enemy.hpp"

class RadScorpion: public Enemy
{
public:
	RadScorpion();
	RadScorpion(const RadScorpion &);
	virtual ~RadScorpion();
	void operator = (const RadScorpion &);
};
