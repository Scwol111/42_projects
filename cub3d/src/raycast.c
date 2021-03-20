/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:45:21 by tclaudin          #+#    #+#             */
/*   Updated: 2021/03/14 15:25:47 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_bool		check_map(char *map[], t_ray *ray, t_pl_po *po, t_pl_po *pl)
{
	t_point			dot;
	static t_point	size = {-1, -1};

	if (size.x == -1 && size.y == -1)
		size = map_size(map);
	if (po->x < 0 || po->y < 0)
		return (FALSE);
	if ((ray->horz || ray->angle > 180) && !(ray->angle > 90 && ray->angle <
	270 && ray->horz))
	{
		dot.x = ft_sc(po->x);
		dot.y = ft_sc(po->y);
	}
	else
	{
		dot.x = (int)ceil(po->x) * TO_SC;
		dot.y = (int)ceil(po->y) * TO_SC;
	}
	if (dot.x <= 0 || dot.y <= 0 || dot.x >= size.x || dot.y >= size.y)
		return (FALSE);
	if (map[dot.y][dot.x] == '1')
		return (FALSE);
	if (map[dot.y][dot.x] == '2')
		add_sprite(ray, &dot, pl);
	return (TRUE);
}

double		horizontal(char *map[], t_player *pl, t_ray *ray, t_pl_po *po)
{
	double	cotan;

	ray->horz = TRUE;
	if (ray->angle >= 0 && ray->angle <= 180)
		po->y = floor(pl->pos->y * TO_SC) * SCALE - 1;
	else
		po->y = floor(pl->pos->y * TO_SC) * SCALE + SCALE;
	cotan = 1 / ft_tan(ray->angle);
	po->x = pl->pos->x + (pl->pos->y - po->y) * cotan;
	while (check_map(map, ray, po, pl->pos))
	{
		if (ray->angle >= 0.0 && ray->angle <= 180.0)
		{
			po->y -= SCALE;
			po->x += SCALE * cotan;
		}
		else
		{
			po->y += SCALE;
			po->x -= SCALE * cotan;
		}
	}
	return (fabs((pl->pos->y - po->y) / ft_sin(ray->angle)));
}

double		vertical(char *map[], t_player *pl, t_ray *ray, t_pl_po *po)
{
	ray->horz = FALSE;
	if (ray->angle >= 90 && ray->angle <= 270)
		po->x = floor(pl->pos->x * TO_SC) * SCALE - 1;
	else
		po->x = floor(pl->pos->x * TO_SC) * SCALE + SCALE;
	po->y = pl->pos->y + (pl->pos->x - po->x) * ft_tan(ray->angle);
	while (check_map(map, ray, po, pl->pos))
	{
		if (ray->angle >= 90.0 && ray->angle <= 270.0)
		{
			po->x -= SCALE;
			po->y += SCALE * ft_tan(ray->angle);
		}
		else
		{
			po->x += SCALE;
			po->y -= SCALE * ft_tan(ray->angle);
		}
	}
	return (fabs((pl->pos->x - po->x) / ft_cos(ray->angle)));
}

double		find_wall(char *map[], t_player *pl, t_ray *ray)
{
	double	dist1;
	double	dist2;
	t_pl_po	po1;
	t_pl_po	po2;

	dist1 = horizontal(map, pl, ray, &po1);
	dist2 = vertical(map, pl, ray, &po2);
	if (dist1 < dist2)
	{
		ray->point = po1;
		return (find_wall_side(ray->angle, dist1, &ray->wall, 'x'));
	}
	ray->point.x = po2.x;
	ray->point.y = po2.y;
	return (find_wall_side(ray->angle, dist2, &ray->wall, 'y'));
}

int			raycast(t_all *all)
{
	t_ray	*ray;
	int		col;

	raycast_utils(all, &col);
	if (!(ray = ray_create(all)))
		return (FALSE);
	while (ray->angle < ray->end)
	{
		ray->dist[col] = find_wall(all->data->map, all->pl, ray) *
		ft_cos(all->pl->pov - ray->angle);
		all->save = *render(all, ray, &all->save, col++);
		ray->angle += ray->angle_plus;
		if (ray->angle > MAX_ROT)
		{
			ray->angle -= MAX_ROT;
			ray->end -= MAX_ROT;
		}
	}
	if (ray->sprt_count > 0)
		all->save = *render_sprite(&all->save, ray, all);
	mlx_clear_window(all->mlx->mlx_init, all->mlx->mlx_win);
	mlx_put_image_to_window(all->mlx->mlx_init, all->mlx->mlx_win,
	all->save.img, 0, 0);
	free(ray);
	return (TRUE);
}
