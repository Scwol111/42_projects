/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 17:14:28 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 17:20:15 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int			find_on_map(char *map[], t_player *pl)
{
	int i;
	int j;

	i = 0;
	while (map[i])
	{
		pl->pos->y = i * SCALE;
		j = 0;
		while (map[i][j] != 0)
		{
			pl->pos->x = j * SCALE;
			if (map[i][j] == 'N')
				return (POV_N);
			if (map[i][j] == 'S')
				return (POV_S);
			if (map[i][j] == 'W')
				return (POV_W);
			if (map[i][j] == 'E')
				return (POV_E);
			j++;
		}
		i++;
	}
	return (ft_errors(PLERR));
}

t_player	*create_player(t_data *data)
{
	t_player	*pl;

	if (!(pl = (t_player*)malloc(sizeof(t_player))))
		return (ft_errors_null(ALLER));
	if (!(pl->pos = (t_pl_po*)malloc(sizeof(t_pl_po))))
		return (ft_errors_null(ALLER));
	pl->pov = find_on_map(data->map, pl);
	pl->pos->x += SCALE / 2;
	pl->pos->y += SCALE / 2;
	return (pl);
}

void		player_free(t_player *pl)
{
	if (pl)
	{
		if (pl->pos != NULL)
			free(pl->pos);
		free(pl);
	}
}

void		change_position(t_data *data, t_player *pl, short way)
{
	t_point	dot;
	t_point	new;
	int		angle;

	angle = pl->pov;
	dot.x = ft_sc(pl->pos->x);
	dot.y = ft_sc(pl->pos->y);
	if (way == 0)
		angle += 270;
	if (way == 2)
		angle += 90;
	if (way == 1)
		angle += 180;
	if (angle > 360)
		angle -= 360;
	new.x = ft_sc(pl->pos->x + SPEED * ft_cos(angle) * 1.75);
	new.y = ft_sc(pl->pos->y - SPEED * ft_sin(angle) * 1.75);
	if (data->map[dot.y][new.x] != '1')
		pl->pos->x += floor(SPEED * ft_cos(angle));
	if (data->map[new.y][dot.x] != '1')
		pl->pos->y -= floor(SPEED * ft_sin(angle));
}

void		change_pov(t_player *pl, short way)
{
	if (way == 124)
	{
		pl->pov += ROTATION;
		if (pl->pov >= MAX_ROT)
			pl->pov -= MAX_ROT;
	}
	if (way == 123)
	{
		pl->pov -= ROTATION;
		if (pl->pov < MIN_ROT)
			pl->pov += MAX_ROT;
	}
}
