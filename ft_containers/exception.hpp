/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:05:22 by tclaudin          #+#    #+#             */
/*   Updated: 2021/05/02 14:20:25 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <iostream>

namespace ft
{
	class IndexOutOfRangeException : public std::exception
	{
		public:
			virtual const char* what() const throw()
			{
				return "Index out of range";
			}
	};
}

#endif
