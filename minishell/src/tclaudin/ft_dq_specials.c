/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dq_specials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 13:37:10 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/13 12:58:13 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_dq_sp_slash(t_parse *pars, char **str_org, size_t *i)
{
	char *str;

	str = *str_org + 1;
	if (str)
	{
		if (ft_strchr(DQ_SHILD, *str) == NULL)
			str--;
		if (pars->cur_size[*i] + 1 >= pars->size[*i])
			pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
		pars->arg[*i][pars->cur_size[*i]++] = *(str);
		*str_org = str;
	}
	return (0);
}

int		ft_dq_specials(t_parse *pars, char **str_org, size_t *i, char c)
{
	if (c == '\\')
		return (ft_dq_sp_slash(pars, str_org, i));
	if (c == '$')
		return (ft_sp_dollar(pars, str_org, i));
	return (1);
}

int		ft_sp_dquote(t_parse *pars, char **str_org, size_t *i)
{
	char *str;

	str = *str_org + 1;
	while (str && *str && *str != '\"')
	{
		if (ft_strchr(D_SPECIALS, *str))
		{
			if (*str == '\\')
				ft_dq_sp_slash(pars, &str, i);
			else if (*str == '$')
				ft_sp_dollar(pars, &str, i);
		}
		else
		{
			if (pars->cur_size[*i] + 1 >= pars->size[*i])
				pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
			pars->arg[*i][pars->cur_size[*i]++] = *str;
		}
		str++;
	}
	pars->fl = '\1';
	*str_org = str;
	return (0);
}
