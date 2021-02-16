/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 19:20:53 by tclaudin          #+#    #+#             */
/*   Updated: 2020/11/20 16:20:33 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			ft_rd_qoutes(char **name, char **str_org, t_size *sz)
{
	char *str;

	str = *str_org;
	str++;
	while (*str && *str != '\'')
	{
		if (sz->curr + 1 >= sz->size)
			*name = ft_remade(*name, &sz->size);
		*name[sz->curr++] = *str;
		str++;
	}
	*str_org = str;
	return (0);
}

int			ft_rd_slash(char **name, char **str_org, t_size *sz)
{
	char *str;

	str = *str_org;
	str++;
	if (*str)
	{
		if (sz->curr + 1 >= sz->size)
			*name = ft_remade(*name, &sz->size);
		*name[sz->curr++] = *str;
		*str_org = str;
	}
	return (0);
}

int			ft_rd_tilda(char **name, char **str_o, t_size *sz, t_env_var **env)
{
	char	*str;
	int		fl;

	str = *str_o;
	fl = 1;
	if (!*(str + 1) || *(str + 1) == ' ' || *(str + 1) == '/')
	{
		sz->curr += ft_strlen(env[0]->value);
		while (sz->curr >= sz->size)
			*name = ft_remade(*name, &sz->size);
		ft_strlcat(*name, env[0]->value, sz->size);
		fl = 0;
	}
	if (fl)
	{
		if (sz->curr + 1 >= sz->size)
			*name = ft_remade(*name, &sz->size);
		*name[sz->curr++] = *str;
	}
	return (0);
}

static int	ft_help(t_size *sz, t_env_var **env, char *name, char **add)
{
	int res;
	int ret;

	ret = 1;
	if (name)
	{
		if ((res = ft_env_find(env, name)) >= 0)
		{
			sz->curr += ft_strlen(env[res]->value);
			while (sz->curr >= sz->size)
				*add = ft_remade(*add, &sz->size);
			ft_strlcat(*add, env[res]->value, sz->size);
			ret = 0;
		}
		free(name);
	}
	return (ret);
}

int			ft_rd_dollar(char **name, char **st_o, t_size *sz, t_env_var **env)
{
	char	*envp;
	t_size	size;
	char	*str;

	str = *st_o + 1;
	envp = NULL;
	size.size = 0;
	size.curr = 0;
	while (str && *str && ft_strchr(SPECIALS, *str) == NULL)
	{
		if (size.curr + 1 >= size.size)
			envp = ft_remade(envp, &size.size);
		envp[size.curr++] = *(str++);
	}
	if (!ft_help(sz, env, envp, name))
	{
		if (*str == '\\')
			str++;
		if (sz->curr + 1 >= sz->size)
			*name = ft_remade(*name, &sz->size);
		*name[sz->curr++] = *str;
	}
	*st_o = str - 1;
	return (0);
}
