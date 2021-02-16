/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_work.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:59:33 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 16:33:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_data	*new_data(void)
{
	t_data *dt;

	if (!(dt = (t_data*)malloc(sizeof(t_data))))
		return (ft_errors_null(ALLER));
	dt->ceil_rgb = -1;
	dt->floor_rgb = -1;
	dt->east = NULL;
	dt->hight = -1;
	dt->map = NULL;
	dt->north = NULL;
	dt->south = NULL;
	dt->sprite = NULL;
	dt->west = NULL;
	dt->width = -1;
	dt->map_size = 0;
	dt->map_current_cout = 0;
	return (dt);
}

void	data_free(t_data *data)
{
	int i;

	i = 0;
	if (data)
	{
		if (data->east)
			free(data->east);
		if (data->north)
			free(data->north);
		if (data->south)
			free(data->south);
		if (data->west)
			free(data->west);
		if (data->sprite)
			free(data->sprite);
		if (data->map)
		{
			while (data->map[i])
				free(data->map[i++]);
			free(data->map);
		}
		free(data);
	}
}

t_bool	data_find_null(t_data *dt)
{
	if (!dt)
		return (TRUE);
	if (dt->width < 0 || dt->hight < 0 || dt->ceil_rgb < 0 || dt->floor_rgb < 0)
		return (TRUE);
	if (!dt->east || !dt->north || !dt->south || !dt->west || !dt->sprite)
		return (TRUE);
	if (!dt->map || !valid_map(dt))
		return (TRUE);
	return (FALSE);
}

t_bool	data_ready_for_map(t_data *dt)
{
	t_bool fl;

	fl = FALSE;
	if (dt->width >= 0 && dt->hight >= 0 && dt->ceil_rgb >= 0 &&
	dt->floor_rgb >= 0)
		fl = TRUE;
	if (fl && dt->east && dt->west && dt->north && dt->south && dt->sprite)
		return (TRUE);
	return (FALSE);
}
