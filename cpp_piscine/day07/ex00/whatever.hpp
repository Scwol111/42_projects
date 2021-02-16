/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 19:32:54 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/17 18:03:41 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <typename _T>
void swap(_T &_first, _T &_second)
{
	_T _save = _first;

	_first = _second;
	_second = _save;
}

template <typename _T>
_T &min(_T &_first, _T &_second)
{
	if (_first < _second)
		return _first;
	return _second;
}

template <typename _T>
_T &max(_T &_first, _T &_second)
{
	if (_first > _second)
		return _first;
	return _second;
}

#endif