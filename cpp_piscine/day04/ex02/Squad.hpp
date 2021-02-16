/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Squad.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 16:29:35 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/10 12:31:35 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ISquad.hpp"
#include "ISpaceMarine.hpp"

class Squad: public ISquad
{
private:
	const int _buff;
	int _count;
	int _max;
	ISpaceMarine **_squad;

public:
	Squad();
	Squad(const ISquad *);
	Squad(const ISquad &);
	~Squad();
	virtual int getCount() const;
	virtual ISpaceMarine* getUnit(int) const;
	virtual int push(ISpaceMarine*);
	void operator = (const Squad &);
};

