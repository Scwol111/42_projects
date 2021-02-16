/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 13:13:15 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/13 19:05:46 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		raycast_utils(t_all *all, int *col)
{
	if (all->save.img != NULL)
		mlx_destroy_image(all->mlx->mlx_init, all->save.img);
	all->save.img = mlx_new_image(all->mlx->mlx_init, all->data->width,
	all->data->hight);
	if (all->save.img == NULL)
		return (ft_errors(IMGER));
	all->save.addr = mlx_get_data_addr(all->save.img, &all->save.bits_per_pixel,
	&all->save.line_length, &all->save.endian);
	*col = 0;
	return (0);
}

t_ray	*ray_create(t_all *all)
{
	t_ray *ray;

	if (!(ray = (t_ray*)malloc(sizeof(t_ray))))
		return (ft_errors_null(ALLER));
	ray->angle = all->pl->pov - (FOV / 2);
	ray->end = all->pl->pov + (FOV / 2);
	if (ray->angle < MIN_ROT)
		ray->angle += MAX_ROT;
	if (ray->angle > ray->end)
		ray->end += MAX_ROT;
	ray->sprt_count = 0;
	ray->proj_pl = all->data->width / 2 / ft_tan(FOV / 2) * SCALE;
	ray->angle_plus = (double)FOV / (double)all->data->width;
	return (ray);
}

double	find_wall_side(double angle, double res, char *ch, char type)
{
	if (angle >= 360)
		angle -= 360;
	if (type == 'x')
	{
		if (angle >= 0 && angle < 180)
			*ch = 'S';
		else
			*ch = 'N';
	}
	if (type == 'y')
	{
		if (angle >= 90 && angle < 270)
			*ch = 'W';
		else
			*ch = 'E';
	}
	return (res);
}
