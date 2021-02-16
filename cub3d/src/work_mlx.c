/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 16:57:51 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/07 14:08:22 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_mlx	*create_mlx(t_data *data)
{
	t_mlx	*mlx;
	int		x;
	int		y;

	if (!(mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (ft_errors_null(ALLER));
	if (!(mlx->mlx_init = mlx_init()))
		return (ft_errors_null(MLXIN));
	mlx_get_screen_size(mlx->mlx_init, &x, &y);
	data->width = ft_min(data->width, x);
	data->hight = ft_min(data->hight, y);
	if (!(mlx->mlx_win = mlx_new_window(mlx->mlx_init, data->width,
	data->hight, NAME)))
		return (ft_errors_null(MLXWI));
	mlx->can_work = TRUE;
	return (mlx);
}

void	close_mlx(t_mlx *mlx, t_data *data)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->mlx_init, mlx->mlx_win);
		free(mlx);
	}
	if (data)
		data_free(data);
}
