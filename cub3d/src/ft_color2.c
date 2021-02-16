/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:42:49 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/09 15:34:48 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/colors.h"

int		add_shade(double distance, int color)
{
	double r;
	double g;
	double b;

	r = get_r(color) * distance;
	g = get_g(color) * distance;
	b = get_b(color) * distance;
	return (create_trgb(get_t(color), (int)r, (int)g, (int)b));
}

int		get_opposite(int color)
{
	int r;
	int g;
	int b;

	r = RGB_MAX - get_r(color);
	b = RGB_MAX - get_b(color);
	g = RGB_MAX - get_g(color);
	return (create_trgb(get_t(color), r, g, b));
}
