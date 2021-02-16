/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 15:52:37 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 12:54:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

void	*get_images_utils(void *mlx, char *path, t_point *point)
{
	int		fd;
	void	*img;

	if (ft_strnstr(path, XPM, ft_strlen(path)))
	{
		if ((fd = open(path, O_RDONLY)) > 0)
		{
			close(fd);
			if (!(img = mlx_xpm_file_to_image(mlx, path, &point->x, &point->y)))
				return (ft_errors_null(PICIN));
		}
		else
			return (ft_errors_null(PICER));
	}
	else
		return (ft_errors_null(XPMER));
	return (img);
}

t_info	*create_info(void)
{
	t_info *inf;

	if (!(inf = (t_info*)malloc(sizeof(t_info))))
		return (ft_errors_null(ALLER));
	if (!(inf->north = (t_image*)malloc(sizeof(t_image))))
		return (ft_errors_null(ALLER));
	if (!(inf->south = (t_image*)malloc(sizeof(t_image))))
		return (ft_errors_null(ALLER));
	if (!(inf->west = (t_image*)malloc(sizeof(t_image))))
		return (ft_errors_null(ALLER));
	if (!(inf->east = (t_image*)malloc(sizeof(t_image))))
		return (ft_errors_null(ALLER));
	if (!(inf->sprite = (t_image*)malloc(sizeof(t_image))))
		return (ft_errors_null(ALLER));
	return (inf);
}

t_image	*get_images_utils2(t_image *img)
{
	if (!(img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
	&img->line_length, &img->endian)))
		return (ft_errors_null(PICLO));
	return (img);
}

t_info	*get_texture(t_all *all)
{
	t_info *inf;

	if (!(inf = create_info()))
		return (NULL);
	if (!(inf->north->img = get_images_utils(all->mlx->mlx_init,
	all->data->north, &inf->no_wh)))
		return (NULL);
	inf->north = get_images_utils2(inf->north);
	if (!(inf->south->img = get_images_utils(all->mlx->mlx_init,
	all->data->south, &inf->so_wh)))
		return (NULL);
	inf->south = get_images_utils2(inf->south);
	if (!(inf->west->img = get_images_utils(all->mlx->mlx_init,
	all->data->west, &inf->we_wh)))
		return (NULL);
	inf->west = get_images_utils2(inf->west);
	if (!(inf->east->img = get_images_utils(all->mlx->mlx_init,
	all->data->east, &inf->ea_wh)))
		return (NULL);
	inf->east = get_images_utils2(inf->east);
	if (!(inf->sprite->img = get_images_utils(all->mlx->mlx_init,
	all->data->sprite, &inf->sp_wh)))
		return (NULL);
	inf->sprite = get_images_utils2(inf->sprite);
	return (inf);
}
