/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 19:35:59 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/29 16:59:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

double	ft_tan(double angle)
{
	double res;

	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	res = tan(angle * TO_PI);
	return (res);
}

double	ft_cos(double angle)
{
	double res;

	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	res = cos(angle * TO_PI);
	return (res);
}

double	ft_sin(double angle)
{
	double res;

	while (angle >= 360)
		angle -= 360;
	while (angle < 0)
		angle += 360;
	res = sin(angle * TO_PI);
	return (res);
}

int		ft_sc(double x)
{
	double res;

	res = x * TO_SC;
	return ((int)res);
}

t_point	map_size(char **map)
{
	int		i;
	int		j;
	int		max;
	t_point po;

	i = 0;
	max = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != 0)
			j++;
		max = ft_max(j, max);
		i++;
	}
	po.x = max;
	po.y = i;
	return (po);
}
