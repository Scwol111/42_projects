/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 12:54:09 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/08 19:10:50 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_help(t_env_var ***e, char *name, char *value)
{
	int			i;
	t_env_var	**env;

	env = *e;
	i = 2;
	while (env[i])
		i++;
	if (!(env[i] = (t_env_var*)malloc(sizeof(t_env_var))))
		return (1);
	env[i]->name = ft_strdup(name);
	env[i]->value = NULL;
	if (value)
		env[i]->value = ft_strdup(value);
	*e = env;
	return (0);
}

int			ft_add_env(t_env_var ***e, char *name, char *value)
{
	int			i;
	t_env_var	**env;

	env = *e;
	if (ft_strncmp(name, "?", 10) != 0)
	{
		if ((i = ft_env_find(env, name)) > 0)
		{
			free(env[i]->value);
			env[i]->value = NULL;
			if (value)
				env[i]->value = ft_strdup(value);
		}
		else
			ft_help(&env, name, value);
	}
	*e = env;
	return (0);
}

int			ft_del_env(t_env_var ***e, char *name)
{
	int			i;
	t_env_var	**env;

	i = -1;
	env = *e;
	if (ft_strncmp(name, "?", 10) != 0 && ((i = ft_env_find(env, name)) > 0))
	{
		free(env[i]->name);
		if (env[i]->value)
			free(env[i]->value);
		free(env[i]);
		i++;
		while (env[i])
		{
			env[i - 1] = env[i];
			i++;
		}
		env[i - 1] = NULL;
	}
	*e = env;
	return (0);
}

char		**reset_env(t_env_var **envp)
{
	char	**env;
	int		i;
	int		j;
	t_size	sz;

	if (!(env = (char**)ft_calloc(BUFFER_SIZE + 1, sizeof(char*))))
		return (NULL);
	i = 2;
	j = 0;
	while (envp[i])
	{
		sz.curr = ft_strlen(envp[i]->name) + 2;
		if (envp[i]->value)
			sz.curr += ft_strlen(envp[i]->value);
		sz.size = 0;
		while (sz.curr >= sz.size)
			env[j] = ft_remade(env[j], &sz.size);
		ft_strlcat(env[j], envp[i]->name, sz.size);
		ft_strlcat(env[j], "=", sz.size);
		if (envp[i]->value)
			ft_strlcat(env[j], envp[i]->value, sz.size);
		i++;
		j++;
	}
	return (env);
}
