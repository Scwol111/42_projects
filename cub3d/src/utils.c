/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 16:09:09 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/16 16:01:02 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

char	*ft_skip_space(char *str)
{
	while (*str != 0 && *str == ' ')
		str++;
	return (str);
}

char	*ft_next_word(char *str)
{
	while (*str != 0 && *str != ' ' && *str != '\n' && *str != '\t' &&
	*str != '\v' && *str != '\f' && *str != '\r')
		str++;
	return (str);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

t_bool	map_validate_str(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 0)
		return (ft_errors(MPINP));
	while (str[i] != 0)
	{
		if (!ft_strchr(MAP_SYMBOL, str[i]) && str[i] != 0)
			return (ft_errors(MPINP));
		i++;
	}
	return (TRUE);
}
