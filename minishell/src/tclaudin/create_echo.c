/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:12:39 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/09 18:47:26 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static short	ft_help(char **str, size_t *i)
{
	int		flag;
	t_size	sz;

	sz.size = 0;
	flag = 1;
	while (str[sz.size])
	{
		sz.curr = 0;
		if (str[sz.size][sz.curr] != '-')
			return (flag);
		else
			sz.curr++;
		while (str[sz.size][sz.curr])
		{
			if (str[sz.size][sz.curr] != 'n')
				return (flag);
			sz.curr++;
		}
		flag = 0;
		sz.size++;
		*i = *i + 1;
	}
	return (flag);
}

int				create_echo(t_parse *pars)
{
	char	*str;
	int		flag;
	size_t	i;
	t_size	sz;

	sz.size = BUFFER_SIZE + 1;
	sz.curr = 0;
	i = 0;
	if (!(str = (char*)ft_calloc(sz.size, sizeof(char))))
		return (-1);
	if (pars->arg[++i] && !ft_help(pars->arg + 1, &i))
		flag = 1;
	while (pars->arg[i])
	{
		sz.curr += ft_strlen(pars->arg[i]) + 1;
		while (sz.curr >= sz.size)
			str = ft_remade(str, &sz.size);
		if (((i > 2 && flag) || (i > 1 && !flag)) && ft_strlen(str) > 0)
			ft_strlcat(str, " ", sz.size);
		ft_strlcat(str, pars->arg[i], sz.size);
		i++;
	}
	ft_echo(str, flag);
	free(str);
	return (0);
}
