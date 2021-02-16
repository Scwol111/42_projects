/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:01:21 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/18 11:25:43 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

template <typename _T>
void iter(_T *arr, size_t size, void (&f)(_T const&))
{
	for (size_t i = 0; i < size; i++)
		f(arr[i]);
}

#endif