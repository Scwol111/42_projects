/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 12:11:32 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 17:59:39 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

double	get_angle(double x, double y)
{
	double angle;

	angle = 180 - ft_acos(x);
	if ((x >= 0 && y >= 0) || (x <= 0 && y >= 0))
		return (angle);
	return (MAX_ROT - angle);
}

double	ft_sprt_conv(int a)
{
	double res;

	res = a * SCALE + SCALE / 2;
	return (res);
}

t_r_spr	*create_sprite(t_all *all, int *begin)
{
	t_r_spr *sprt;

	if (!(sprt = (t_r_spr*)malloc(sizeof(t_r_spr))))
		return (ft_errors_null(ALLER));
	sprt->img = all->info->sprite;
	sprt->width = all->data->width;
	sprt->height = all->data->hight;
	sprt->y = all->info->sp_wh.y;
	sprt->x = all->info->sp_wh.x;
	*begin = all->pl->pov - FOV / 2;
	return (sprt);
}

t_bool	check_sprite(t_ray *ray, t_point *dot)
{
	int i;

	i = 0;
	while (i < ray->sprt_count)
	{
		if (ray->sprite[i].pos.x == dot->x && ray->sprite[i].pos.y == dot->y)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	sprite_utils(t_all *all, t_r_spr *sprt, t_ray *ray, int i)
{
	sprt->dist = ray->sprite[i].dist;
	sprt->angle = get_angle((all->pl->pos->x - ray->sprite[i].po.x) /
	sprt->dist, (all->pl->pos->y - ray->sprite[i].po.y) / sprt->dist);
	sprt->dist *= ft_cos(all->pl->pov - sprt->angle);
	sprt->h = (int)(ray->proj_pl / sprt->dist);
	sprt->w = all->info->sp_wh.x / all->info->sp_wh.y * sprt->h;
}
