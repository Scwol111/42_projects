/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 17:43:15 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 13:58:37 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void		my_mlx_pixel_put(t_image *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int			my_get_img_color(t_image *img, int x, int y)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int*)dst);
}

t_render	*render_utils(t_image *img, int hei, int clo)
{
	t_render *rnd;

	if (!(rnd = (t_render*)malloc(sizeof(t_render))))
		return (ft_errors_null(ALLER));
	rnd->tex = img;
	rnd->hei = hei;
	rnd->clo = clo;
	return (rnd);
}

t_render	*render_utils2(t_all *all, t_ray *ray)
{
	t_render *rnd;

	if (ray->wall == 'W')
		rnd = render_utils(all->info->west, all->info->we_wh.y,
		(int)(all->info->we_wh.x * fmod(ray->point.y, SCALE) * TO_SC));
	if (ray->wall == 'E')
		rnd = render_utils(all->info->east, all->info->ea_wh.y,
		(int)(all->info->ea_wh.x * fmod(ray->point.y, SCALE) * TO_SC));
	if (ray->wall == 'N')
		rnd = render_utils(all->info->north, all->info->no_wh.y,
		(int)(all->info->no_wh.x * fmod(ray->point.x, SCALE) * TO_SC));
	if (ray->wall == 'S')
		rnd = render_utils(all->info->south, all->info->so_wh.y,
		(int)(all->info->so_wh.x * fmod(ray->point.x, SCALE) * TO_SC));
	return (rnd);
}

t_image		*render(t_all *all, t_ray *ray, t_image *img, int col)
{
	int			h;
	t_point		count;
	t_render	*rnd;

	h = (int)(ray->proj_pl / ray->dist[col]);
	count.x = -1;
	rnd = render_utils2(all, ray);
	if (h <= all->data->hight)
		count.y = 0;
	else
		count.y = (h - all->data->hight) / 2;
	while (++count.x < all->data->hight)
	{
		if (count.x <= (all->data->hight - h) / 2)
			my_mlx_pixel_put(img, col, count.x, all->data->ceil_rgb);
		else if (count.x >= (all->data->hight + h) / 2)
			my_mlx_pixel_put(img, col, count.x, all->data->floor_rgb);
		else
			my_mlx_pixel_put(img, col, count.x, my_get_img_color(rnd->tex,
			rnd->clo, (count.y++ * rnd->hei / h)));
	}
	free(rnd);
	return (img);
}
