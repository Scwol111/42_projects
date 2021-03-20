/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ErrorInfo.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:41:44 by tclaudin          #+#    #+#             */
/*   Updated: 2021/02/21 18:14:06 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORINFO_HPP
#define ERRORINFO_HPP

#include <iostream>
#include <algorithm>
#include <vector>

class ErrorInfo 
{
private:
	std::vector<int>	_code;
	int					_request;
	std::string			_name;

public:
	~ErrorInfo();
	ErrorInfo();
	ErrorInfo& operator=(ErrorInfo const& src);
	ErrorInfo(ErrorInfo const& src);

	void		setName(std::string const &);
	void		addCode(int);
	void		setRequest(int);
	std::string	findError(int) const;
};

#endif // !ERRORINFO_HPP
