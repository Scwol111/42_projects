/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 12:02:31 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/09 18:36:03 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_sp_space(t_parse *pars, char **str_org, size_t *i)
{
	char *str;

	str = *str_org;
	str = ft_skip_space(str);
	if (*i + 1 >= pars->sz)
	{
		ft_reload_parse(pars);
		*i = *i + 1;
	}
	if (pars->fl)
	{
		pars->fl = 0;
		*i = *i + 1;
	}
	*str_org = str - 1;
	return (0);
}

int			ft_sp_qoutes(t_parse *pars, char **str_org, size_t *i)
{
	char *str;

	str = *str_org;
	str++;
	while (*str && *str != '\'')
	{
		if (pars->cur_size[*i] + 1 >= pars->size[*i])
			pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
		pars->arg[*i][pars->cur_size[*i]++] = *str;
		str++;
	}
	pars->fl = '\1';
	*str_org = str;
	return (0);
}

static void	ft_help(t_parse *pars, size_t *i, char *name, char **str)
{
	int res;
	int	j;

	j = 0;
	if ((res = ft_env_find(pars->env, name)) >= 0)
	{
		while (pars->env[res]->value[j])
		{
			if (pars->env[res]->value[j] == ' ')
				*i += 1;
			else
			{
				if (pars->cur_size[*i] + 1 >= pars->size[*i])
					pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
				pars->arg[*i][pars->cur_size[*i]++] = pars->env[res]->value[j];
			}
			j++;
		}
		pars->fl = '\1';
	}
	else if (**str == '\\')
		*str += 1;
	free(name);
}

int			ft_sp_dollar(t_parse *pars, char **str_org, size_t *i)
{
	char	*name;
	size_t	size;
	size_t	curr;
	char	*str;

	str = *str_org + 1;
	name = NULL;
	size = 0;
	curr = 0;
	while (str && *str && ft_strchr(DOLLAR_END, *str) == NULL)
	{
		if (curr + 1 >= size)
			name = ft_remade(name, &size);
		name[curr++] = *(str++);
	}
	if (name)
		ft_help(pars, i, name, &str);
	else
	{
		if (pars->cur_size[*i] + 1 >= pars->size[*i])
			pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
		pars->arg[*i][pars->cur_size[*i]++] = *(str - 1);
	}
	*str_org = str - 1;
	return (0);
}

int			ft_specials(t_parse *pars, char **str_org, size_t *i, char c)
{
	int r;

	if (c == ' ')
		return (ft_sp_space(pars, str_org, i));
	if (c == '\'')
		return (ft_sp_qoutes(pars, str_org, i));
	if (c == '\\')
		return (ft_sp_slash(pars, str_org, i));
	if (c == '$')
		return (ft_sp_dollar(pars, str_org, i));
	if (c == '\"')
		return (ft_sp_dquote(pars, str_org, i));
	if (c == ';')
		return (ft_sp_dots(pars, str_org, i));
	if (c == '~')
		return (ft_sp_tilda(pars, str_org, i));
	if (c == '>' || c == '<')
	{
		if ((r = ft_redirects(str_org, pars->env, &pars->now_fd, pars)) == 258)
			**str_org = 0;
		return (r);
	}
	if (c == '|')
		return (ft_sp_pipe(pars, str_org, i));
	return (1);
}
