/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 14:28:32 by loscar            #+#    #+#             */
/*   Updated: 2020/12/13 13:51:56 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void			fun_put(char **input, t_env_var ***env, int i)
{
	char *pointer;

	pointer = ft_strrchr(input[i], '=');
	if (pointer != NULL)
	{
		*pointer = 0;
		pointer++;
	}
	ft_add_env(env, input[i], pointer);
}

static void			swap(t_env_var **a, t_env_var **b)
{
	t_env_var *save;

	save = *a;
	*a = *b;
	*b = save;
}

static t_env_var	**sort(t_env_var **env)
{
	int			i;
	int			k;
	int			n;
	t_env_var	**e;

	i = 2;
	n = 0;
	while (env[i++])
		n++;
	e = (t_env_var**)ft_calloc(n + 1, sizeof(t_env_var*));
	n = -1;
	while (env[++n + 2])
		e[n] = env[n + 2];
	i = -1;
	while (++i < n)
	{
		k = -1;
		while (++k < n - 1)
		{
			if (ft_strncmp(e[k]->name, e[k + 1]->name,
				ft_max(ft_strlen(e[k]->name), ft_strlen(e[k + 1]->name))) >= 0)
				swap(&e[k], &e[k + 1]);
		}
	}
	return (e);
}

static void			export_declare(t_env_var ***env)
{
	int			i;
	t_env_var	**e;

	e = sort(*env);
	i = 0;
	while (e[i])
	{
		ft_putstr_fd("declare -x ", 1);
		ft_putstr_fd(e[i]->name, 1);
		if (e[i]->value)
		{
			ft_putstr_fd("=\"", 1);
			ft_putstr_fd(e[i]->value, 1);
			ft_putstr_fd("\"", 1);
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
	free(e);
}

int					export(t_parse *pars, t_env_var ***env,
char **input, int error_cod)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	if (input[i] == NULL)
	{
		export_declare(env);
		return (0);
	}
	while (input[i])
	{
		flag = 0;
		export_pars(pars, i, &error_cod, &flag);
		if (flag == 1)
			fun_put(input, env, i);
		else if (flag == 0 && ft_strncmp(input[i], "_", ft_strlen(input[i])))
			ft_add_env(env, input[i], NULL);
		i++;
	}
	if (error_cod == 1)
		return (1);
	return (0);
}
