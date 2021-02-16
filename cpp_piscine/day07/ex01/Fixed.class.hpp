/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:48:12 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 19:16:42 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
	
public:
	Fixed();
	Fixed(const Fixed &fx);
	Fixed(const int num);
	Fixed(const float num);
	~Fixed();
	void operator = (const Fixed &fx);
	int getRawBits( void ) const;
	void setRawBits( int const raw);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream& operator<< (std::ostream &out, const Fixed &fix);
