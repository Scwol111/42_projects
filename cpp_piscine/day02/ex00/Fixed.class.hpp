/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 16:48:12 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/30 17:04:31 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int	_value;
	static const int _bits = 8;
	
public:
	Fixed();
	Fixed(const Fixed &fx);
	~Fixed();
	void operator = (const Fixed &fx);
	int getRawBits( void ) const;
	void setRawBits( int const raw);
};


