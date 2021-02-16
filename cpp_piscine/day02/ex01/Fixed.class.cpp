/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:49:22 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/30 17:19:52 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.class.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fx): _value(fx.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(int num): _value(num << _bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float num): _value((int)roundf(num * (1 << _bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

void 	Fixed::operator=(const Fixed &fx)
{
	std::cout << "Assignation operator called" << std::endl;
	_value = fx.getRawBits();
}

int 	Fixed::getRawBits() const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void 	Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" << std::endl;
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
