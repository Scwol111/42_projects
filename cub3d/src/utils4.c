/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:09:26 by tclaudin          #+#    #+#             */
/*   Updated: 2020/10/13 16:20:09 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube3d.h"

int		count_komma(char *str)
{
	int res;

	res = 0;
	while (*str != 0)
	{
		if (*str == ',')
			res++;
		str++;
	}
	return (res);
}

int		ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	if (c == '\n')
		return (1);
	return (0);
}

t_bool	valide_str(char *str)
{
	while (*str != 0)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str))
			return (FALSE);
		str++;
	}
	return (TRUE);
}

t_bool	valide_str2(char *str)
{
	while (*str != 0)
	{
		if (!ft_isdigit(*str) && !ft_isspace(*str) && *str != ',')
			return (FALSE);
		str++;
	}
	return (TRUE);
}

int		count_word(char *str)
{
	int res;

	res = 0;
	str = ft_skip_space(str);
	while (*str != 0)
	{
		res++;
		str = ft_skip_space(ft_next_word(str));
	}
	return (res);
}
