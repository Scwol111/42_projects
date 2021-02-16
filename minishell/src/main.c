/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:58:17 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/28 19:02:41 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft(int sig)
{
	write(1, "\b\b  \n", 6);
	write(1, NAME, ft_strlen(NAME));
	(void)sig;
	g_cat = 130;
}

void		ft1(int sig)
{
	(void)sig;
	write(1, "\b\b  \b\b", 6);
	if (g_flag)
	{
		write(1, "^\\Quit: 3\n", 10);
		g_flag = 0;
		g_cat = 131;
	}
}

static int	add_shlvl(t_env_var ***env)
{
	t_env_var	**e;
	int			res;
	int			arg;

	e = *env;
	if ((res = ft_env_find(e, "SHLVL")) != -1)
	{
		arg = ft_atoi(e[res]->value);
		free(e[res]->value);
		e[res]->value = ft_itoa(arg + 1);
		*env = e;
	}
	else
		ft_add_env(env, "SHLVL", "1");
	return (0);
}

static int	ft_help(int flag)
{
	if (flag == 1)
	{
		ft_putendl_fd("exit", 1);
		exit(0);
	}
	g_flag = 0;
	return (1);
}

int			main(int argv, char **argc, char **env)
{
	char		*str;
	t_env_var	**e;
	t_std_fd	*std_fd;

	if (!(std_fd = copy_std_fd()) && argv++ && argc)
		return (1);
	if (!(e = create_env(env)) || add_shlvl(&e))
		return (1);
	signal(SIGINT, ft);
	signal(SIGQUIT, ft1);
	while (1 || (g_cat = 0) == 0)
	{
		if ((g_flag = 0) == 0 && !g_n)
			write(1, SKIP_NAME, ft_strlen(SKIP_NAME));
		write(1, NAME, ft_strlen(NAME));
		get_next_line(0, &str);
		if (str == NULL)
			ft_help(1);
		else
		{
			ft_parse(str, &e, std_fd);
			free(str);
		}
	}
	return (0);
}
