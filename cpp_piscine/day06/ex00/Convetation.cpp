/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convetation.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 13:27:24 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 14:33:12 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convetation.hpp"

Convetation::Convetation(char *str)
{
	_goodC = false;
	_goodD = false;
	_goodI = false;
	_goodF = false;
	try
	{
		_raw = std::stod(str);
		_goodD = true;
	}
	catch(const std::exception& e)
	{
	}
	if (_goodD)
	{
		if (_raw <= std::numeric_limits<char>::max() && _raw >= std::numeric_limits<char>::min())
		{
			_goodC = true;
			_rawc = static_cast<char>(_raw);
		}
		if (_raw <= std::numeric_limits<int>::max() && _raw >= std::numeric_limits<int>::min())
		{
			_goodI = true;
			_rawi = static_cast<int>(_raw);
		}
		if ((_raw <= std::numeric_limits<float>::max() && _raw >= std::numeric_limits<float>::min()) 
		|| _raw == std::numeric_limits<double>::infinity() || _raw == -std::numeric_limits<double>::infinity()
		|| _raw != _raw || (-_raw <= std::numeric_limits<float>::max() && -_raw >= std::numeric_limits<float>::min()))
		{
			_goodF = true;
			_rawf = static_cast<float>(_raw);
		}
	}
}

Convetation::Convetation()
{
	_goodC = false;
	_goodD = false;
	_goodI = false;
	_goodF = false;
}

Convetation::Convetation(const Convetation &copy)
{
	_raw = copy._raw;
	_rawf = copy._rawf;
	_rawi = copy._rawi;
	_rawc = copy._rawc;
	_goodD = copy._goodD;
	_goodF = copy._goodF;
	_goodC = copy._goodC;
	_goodI = copy._goodI;
}

Convetation::~Convetation()
{
}

void Convetation::operator = (const Convetation &copy)
{
	_raw = copy._raw;
	_rawf = copy._rawf;
	_rawi = copy._rawi;
	_rawc = copy._rawc;
	_goodD = copy._goodD;
	_goodF = copy._goodF;
	_goodC = copy._goodC;
	_goodI = copy._goodI;
}

void Convetation::output() const
{
	std::cout << "char: ";
	if (_goodC)
	{
		if (std::isprint(_rawc))
			std::cout << '\'' << _rawc << '\'' <<  std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
	
	std::cout << "int: ";
	if (_goodI)
		std::cout << _rawi << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (_goodF)
	{
		std::cout << _rawf;
		if (_rawf - static_cast<long>(_rawf) == 0)
			std::cout << ".0";
		std::cout << 'f' << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if (_goodD)
	{
		std::cout << _raw;
		if (_raw - static_cast<long>(_raw) == 0)
			std::cout << ".0";
		std::cout << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;
}
