/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:18:59 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/16 18:23:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

double	ft_sqr(double x)
{
	double res;

	res = x * x;
	return (res);
}

int		ft_abs(int x)
{
	if (x >= 0)
		return (x);
	return (-x);
}

double	ft_acos(double x)
{
	double res;

	res = acos(x) * TO_DE;
	return (res);
}

double	ft_asin(double x)
{
	double res;

	res = asin(x) * TO_DE;
	return (res);
}

int		count_number(char *str)
{
	int res;

	res = 0;
	str = ft_skip_space(str);
	while (*str != 0)
	{
		res++;
		while (*str != 0 && ft_isdigit(*str))
			str++;
		while (*str != 0 && (ft_isspace(*str) || *str == ','))
			str++;
	}
	return (res);
}
