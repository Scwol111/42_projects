/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 17:31:30 by tclaudin          #+#    #+#             */
/*   Updated: 2020/11/18 17:40:10 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

t_bool	parse_str_path_utils(char **dest, char *src, char *s)
{
	if (*dest)
		return (ft_errors(ALRHV));
	*dest = ft_strdup(ft_skip_space(src));
	if (!*dest)
		return (ft_errors(ALLER));
	free(s);
	return (TRUE);
}

t_bool	parse_str_color_utils(int *path, char *str, char *s)
{
	int		r;
	int		g;
	int		b;

	if (*path != -1)
		return (ft_errors(ALRHV));
	if (count_komma(str) != 2 || !valide_str2(str) || count_number(str) != 3)
		return (ft_errors(COLER));
	if (ft_isdigit(*ft_skip_space(str)) &&
	ft_isdigit(*(ft_skip_space(ft_strchr(str, ',') + 1))) &&
	ft_isdigit(*(ft_skip_space(ft_strrchr(str, ',') + 1))))
	{
		r = ft_atoi(str);
		g = ft_atoi(ft_strchr(str, ',') + 1);
		b = ft_atoi(ft_strrchr(str, ',') + 1);
	}
	else
		return (ft_errors(COLER));
	if (r < 0 || r > RGB_MAX || g < 0 || g > RGB_MAX || b < 0 || b > RGB_MAX)
		return (ft_errors(COLER));
	*path = create_trgb(0, r, g, b);
	free(s);
	return (TRUE);
}

t_bool	parse_str_res_utils(int *x, int *y, char *str, char *s)
{
	if (*x > -1 || *y > -1)
		return (ft_errors(ALRHV));
	*x = ft_min(ft_atoi(str), MAX_WIDTH);
	if (*x == -1 && *ft_skip_space(str) != '-')
		*x = MAX_WIDTH;
	*y = ft_min(ft_atoi(ft_next_word(ft_skip_space(str))), MAX_HEIGHT);
	if (*y == -1 && *ft_skip_space(ft_next_word(ft_skip_space(str))) != '-')
		*y = MAX_WIDTH;
	if (*x <= 0 || *y <= 0 || !valide_str(str) || count_word(str) != 2)
		return (ft_errors(RESER));
	free(s);
	return (TRUE);
}

t_bool	parse_str(t_data *data, char *str)
{
	char *st;

	st = ft_skip_space(ft_next_word(ft_skip_space(str)));
	if (ft_strnstr(str, "R ", ft_strlen(str)))
		return (parse_str_res_utils(&data->width, &data->hight, st, str));
	if (ft_strnstr(str, "NO ", ft_strlen(str)))
		return (parse_str_path_utils(&data->north, st, str));
	if (ft_strnstr(str, "SO ", ft_strlen(str)))
		return (parse_str_path_utils(&data->south, st, str));
	if (ft_strnstr(str, "WE ", ft_strlen(str)))
		return (parse_str_path_utils(&data->west, st, str));
	if (ft_strnstr(str, "EA ", ft_strlen(str)))
		return (parse_str_path_utils(&data->east, st, str));
	if (ft_strnstr(str, "S ", ft_strlen(str)))
		return (parse_str_path_utils(&data->sprite, st, str));
	if (ft_strnstr(str, "F ", ft_strlen(str)))
		return (parse_str_color_utils(&data->floor_rgb, st, str));
	if (ft_strnstr(str, "C ", ft_strlen(str)))
		return (parse_str_color_utils(&data->ceil_rgb, st, str));
	if (str != NULL && (*str == 0 || *str == '\n'))
	{
		free(str);
		return (TRUE);
	}
	return (ft_errors(UNKER));
}

t_bool	ft_parse(char *fname, t_data *data)
{
	char	*str;
	int		fd;

	if (!(ft_strnstr(fname, ".cub", sizeof(fname))) ||
	ft_strlen((ft_strnstr(fname, ".cub", sizeof(fname)))) != 4)
		return (ft_errors(CUBER));
	if ((fd = open(fname, O_RDONLY)) < 0)
		return (ft_errors(INERR));
	while (get_next_line(fd, &str) > 0)
	{
		if (data_ready_for_map(data))
		{
			if (!map_input(data, str))
				return (ft_errors(MPINP));
		}
		else if (!parse_str(data, str))
			return (FALSE);
	}
	if (data_ready_for_map(data))
		if (!map_input(data, str))
			return (ft_errors(MPINP));
	close(fd);
	if (data_find_null(data))
		return (ft_errors(NOTAL));
	return (TRUE);
}
