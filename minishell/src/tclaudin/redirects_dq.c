/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_dq.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 16:30:25 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/01 15:32:58 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_dq_rd_slash(char **name, char **str_org, t_size *sz)
{
	char *str;

	str = *str_org + 1;
	if (str)
	{
		if (ft_strchr(DQ_SHILD, *str) == NULL)
			str--;
		if (sz->curr + 1 >= sz->size)
			*name = ft_remade(*name, &sz->size);
		*name[sz->curr++] = *str;
		*str_org = str;
	}
	return (0);
}

int		ft_rd_dquote(char **name, char **str_o, t_size *sz, t_env_var **env)
{
	char *str;

	str = *str_o + 1;
	while (str && *str && *str != '\"')
	{
		if (ft_strchr(D_SPECIALS, *str))
		{
			if (*str == '\\')
				ft_dq_rd_slash(name, &str, sz);
			else if (*str == '$')
				ft_rd_dollar(name, &str, sz, env);
		}
		else
		{
			if (sz->curr + 1 >= sz->size)
				*name = ft_remade(*name, &sz->size);
			*name[sz->curr++] = *str;
		}
		str++;
	}
	*str_o = str;
	return (0);
}
