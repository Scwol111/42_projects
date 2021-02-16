/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convetation.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:27:01 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/16 17:28:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <climits>

class Convetation
{
private:
	double _raw;
	float _rawf;
	int _rawi;
	char _rawc;
	bool _goodD;
	bool _goodF;
	bool _goodC;
	bool _goodI;

public:
	Convetation(char *);
	Convetation();
	Convetation(const Convetation &);
	~Convetation();

	void operator = (const Convetation &);
	void output() const;
};
