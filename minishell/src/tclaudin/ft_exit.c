/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:31:30 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/03 02:28:54 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		check_num(char *str)
{
	int	n;
	int	fl;

	n = 0;
	fl = 0;
	if (str)
	{
		if (*str == '-' && fl++)
			str++;
		while (*str)
		{
			if (!ft_isdigit(*str))
				return (1);
			str++;
			n++;
		}
		if (fl && n == 0)
			return (1);
	}
	return (0);
}

static void		ft_help(t_llong *a, t_uchar *b, int *i, short *fl)
{
	*a = 0;
	*b = 0;
	*i = 0;
	*fl = 0;
}

static t_uchar	ft_atouc(char *str, t_parse *pars)
{
	t_llong	resl;
	t_uchar	resu;
	short	fl;
	int		i;

	ft_help(&resl, &resu, &i, &fl);
	if (str[i] == '-' && i++)
		fl = 1;
	while (str[i])
	{
		if (fl)
		{
			resl = resl * 10 - (str[i] - '0');
			resu = resu * 10 - (str[i] - '0');
		}
		else
		{
			resl = resl * 10 + (str[i] - '0');
			resu = resu * 10 + (str[i] - '0');
		}
		if ((fl && resl > 0) || (!fl && resl < 0))
			return (error_exit(255, str, pars));
		i++;
	}
	return (resu);
}

int				ft_exit(char **input, t_parse *pars)
{
	int ret;

	ret = 0;
	if (*input && check_num(*input))
		return (error_exit(255, *input, pars));
	if (*input && *(input + 1))
		return (error_exit(-1, *input, pars));
	if (*input)
		ret = ft_atouc(*input, pars);
	return (ret);
}
