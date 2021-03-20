/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorInfo.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:41:40 by tclaudin          #+#    #+#             */
/*   Updated: 2021/02/22 15:44:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ErrorInfo.hpp"

ErrorInfo::ErrorInfo(): _code()
{
}

ErrorInfo::~ErrorInfo() 
{
}

ErrorInfo::ErrorInfo(ErrorInfo const& src): _code(src._code), _request(src._request), _name(src._name)
{
}

ErrorInfo& ErrorInfo::operator=(ErrorInfo const& src) 
{
	_code = src._code;
	_request = src._request;
	_name = src._name;
	return *this;
}

void	ErrorInfo::setName(std::string const &str)
{
	_name = str;
}

void	ErrorInfo::setRequest(int x)
{
	_request = x;
}

void	ErrorInfo::addCode(int x)
{
	if (!std::binary_search(_code.begin(), _code.end(), x))
		_code.push_back(x);
	std::sort(_code.begin(), _code.end());
}

std::string ErrorInfo::findError(int x) const
{
	if (std::binary_search(_code.begin(), _code.end(), x))
		return _name;
	return "";
}
