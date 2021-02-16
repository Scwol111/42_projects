/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:49:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 19:06:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _value(0)
{
}

Fixed::Fixed(const Fixed &fx): _value(fx.getRawBits())
{
}

Fixed::Fixed(int num): _value(num << _bits)
{
}

Fixed::Fixed(float num): _value((int)roundf(num * (1 << _bits)))
{
}

Fixed::~Fixed()
{
}

void 	Fixed::operator=(const Fixed &fx)
{
	_value = fx.getRawBits();
}

int 	Fixed::getRawBits() const
{
	return (_value);
}

void 	Fixed::setRawBits(int const raw)
{
	_value = raw;
}

int		Fixed::toInt() const
{
	return _value >> _bits;
}

float	Fixed::toFloat() const
{
	return (float)_value / (1 << _bits);
}

std::ostream& operator<< (std::ostream &out, const Fixed &fix)
{
	out << fix.toFloat();
	return out;
}
