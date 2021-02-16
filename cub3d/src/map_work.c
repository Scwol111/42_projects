/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 15:32:54 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/16 16:18:58 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_bool	map_match(t_data *data, int i, int j)
{
	if (data->map[i][j + 1] == ' ' || data->map[i][j + 1] == 0 ||
	data->map[i][j + 1] == '\n')
		return (FALSE);
	if (j > 0 && data->map[i + 1] && i > 0)
	{
		if (data->map[i][j - 1] == ' ' || data->map[i][j - 1] == 0 ||
		data->map[i][j - 1] == '\n')
			return (FALSE);
		if (data->map[i + 1][j] == ' ' || data->map[i + 1][j] == 0 ||
		data->map[i + 1][j] == '\n')
			return (FALSE);
		if (data->map[i - 1][j] == ' ' || data->map[i - 1][j] == 0 ||
		data->map[i - 1][j] == '\n')
			return (FALSE);
	}
	else
		return (FALSE);
	return (TRUE);
}

t_bool	valid_map(t_data *data)
{
	int i;
	int j;
	int err;
	int	player;

	i = -1;
	err = 0;
	player = 0;
	while (data->map[++i] != NULL)
	{
		j = -1;
		while (data->map[i][++j] != 0)
		{
			if (data->map[i][j] == '0' || data->map[i][j] == '2' ||
			ft_strchr("NSWE", data->map[i][j]))
				if (!map_match(data, i, j))
					err++;
			if (ft_strchr("NSWE", data->map[i][j]))
				player++;
		}
	}
	return (choose_map_error(player, err));
}

char	**map_copy(char **new_map, char **map)
{
	int		i;

	i = 0;
	if (map && new_map)
	{
		while (map[i] != NULL)
		{
			new_map[i] = map[i];
			i++;
		}
	}
	return (new_map);
}

char	**new_map_creation(int size)
{
	char	**map;
	int		i;

	if (!(map = (char**)malloc(sizeof(char*) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		map[i++] = NULL;
	return (map);
}

t_bool	map_input(t_data *data, char *str)
{
	char			**new_map;

	if (data->map_current_cout != 0 && !map_validate_str(str))
		return (FALSE);
	if (data->map_current_cout >= data->map_size - 1)
	{
		data->map_size += BUFFER_SIZE;
		if (!(new_map = new_map_creation(data->map_size)))
			return (FALSE);
		map_copy(new_map, data->map);
		free(data->map);
		data->map = new_map;
	}
	data->map[data->map_current_cout++] = str;
	return (TRUE);
}
