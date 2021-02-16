/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:54:43 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/16 14:52:57 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	add_sprite(t_ray *ray, t_point *dot, t_pl_po *pl)
{
	double x;
	double y;

	if (check_sprite(ray, dot))
	{
		ray->sprite[ray->sprt_count].pos.x = dot->x;
		ray->sprite[ray->sprt_count].pos.y = dot->y;
		ray->sprite[ray->sprt_count].po.x = ft_sprt_conv(dot->x);
		ray->sprite[ray->sprt_count].po.y = ft_sprt_conv(dot->y);
		x = ray->sprite[ray->sprt_count].po.x;
		y = ray->sprite[ray->sprt_count].po.y;
		ray->sprite[ray->sprt_count].dist = sqrt(ft_sqr(pl->x - x) +
		ft_sqr(pl->y - y));
		ray->sprt_count++;
	}
}

t_image	*draw_sprite(t_image *img, t_ray *ray, t_r_spr *sprt)
{
	int i;
	int j;
	int	k;
	int color;
	int	clo;

	i = -1;
	while (++i < sprt->w)
	{
		j = -1;
		k = -1;
		clo = i * sprt->x / sprt->w;
		if (sprt->h > sprt->height)
			k = (sprt->h - sprt->height) / 2 - 1;
		if (sprt->start + i >= 0 && sprt->start + i <= sprt->width)
			if (sprt->dist <= ray->dist[sprt->start + i])
				while (++j < sprt->height)
					if (j > (sprt->height - sprt->h) / 2 && j <
					(sprt->height + sprt->h) / 2)
						if ((color = my_get_img_color(sprt->img, clo,
						(++k * sprt->y / sprt->h))) != BLACK)
							my_mlx_pixel_put(img, sprt->start + i, j, color);
	}
	return (img);
}

void	sprite_sort(t_ray *ray)
{
	int			i;
	int			j;
	int			sv;
	double		min;
	t_sprite	sp;

	i = -1;
	while (++i < ray->sprt_count)
	{
		j = i - 1;
		sv = i;
		min = ray->sprite[i].dist;
		while (++j < ray->sprt_count)
		{
			if (ray->sprite[j].dist < min)
			{
				sv = j;
				min = ray->sprite[j].dist;
			}
		}
		sp = ray->sprite[i];
		ray->sprite[i] = ray->sprite[sv];
		ray->sprite[sv] = sp;
	}
}

t_image	*render_sprite(t_image *img, t_ray *ray, t_all *all)
{
	t_r_spr *sprt;
	int		begin;
	int		i;

	i = ray->sprt_count - 1;
	if (!(sprt = create_sprite(all, &begin)))
		return (NULL);
	sprite_sort(ray);
	while (i > -1)
	{
		sprite_utils(all, sprt, ray, i);
		if (!(sprt->angle >= begin - 10 && sprt->angle <= begin + FOV + 10))
		{
			if (sprt->angle > begin)
				sprt->angle -= MAX_ROT;
			else
				begin -= MAX_ROT;
		}
		sprt->start = (int)((sprt->angle - begin) / ray->angle_plus -
		sprt->w / 2.0);
		img = draw_sprite(img, ray, sprt);
		i--;
	}
	free(sprt);
	return (img);
}
