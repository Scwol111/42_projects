/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 11:30:57 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 14:26:45 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T>
typename T::iterator easyfind(T arr, int find)
{
	typename T::iterator result = std::find(arr.begin(), arr.end(), find);
	if (*result == find)
	 	return result;
	throw std::exception();
}

#endif
