/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_another.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:20:45 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/13 13:02:16 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**create_path(t_env_var **env)
{
	int		i;
	char	**path;
	char	*str;
	char	*p;
	size_t	size;

	if (!(path = (char**)ft_calloc(BUFFER_SIZE + 1, sizeof(char*))))
		return (NULL);
	if ((i = ft_env_find(env, "PATH")) > 0)
	{
		str = ft_strdup(env[i]->value);
		i = 0;
		while ((p = ft_strrchr(str, ':')) != NULL)
		{
			size = 0;
			path[i] = ft_remade(path[i], &size);
			path[i++] = ft_strdup(p + 1);
			*p = 0;
		}
		path[i] = ft_remade(path[i], &size);
		path[i++] = ft_strdup(str);
		free(str);
	}
	return (path);
}

int			with_path(t_parse *pars)
{
	char	**env;
	char	**argv;
	char	*str;
	int		ret;

	env = reset_env(pars->env);
	argv = pars->arg;
	str = pars->arg[0];
	ret = execve(str, argv, env);
	destroy_envp(env);
	if (ret != 0)
		return (ft_errors_exec(str, pars));
	return (ret);
}

int			without_path(t_parse *pars)
{
	char	**env;
	char	**argv;
	char	*str;
	t_dint	t;
	t_size	sz;

	env = reset_env(pars->env);
	argv = create_path(pars->env);
	str = pars->arg[0];
	t.x = 1;
	t.y = 0;
	while (t.x != 0 && argv[t.y])
	{
		sz.size = BUFFER_SIZE + 1;
		sz.curr = ft_strlen(argv[t.y]) + ft_strlen(str) + 2;
		while (sz.curr >= sz.size)
			argv[t.y] = ft_remade(argv[t.y], &sz.size);
		ft_strlcat(argv[t.y], "/", sz.size);
		ft_strlcat(argv[t.y], str, sz.size);
		t.x = execve(argv[t.y++], pars->arg, env);
	}
	if (t.x != 0)
		return (error(0, str, pars));
	return (t.x);
}

static void	test(char *str, short type, t_env_var **env)
{
	if (type == 1)
	{
		g_flag = 1;
		if (*str && (((*str == '/' || (*str == '.' && *(str + 1) == '/'))
		&& ft_strnstr(str, "minishell", ft_strlen(str))) ||
		(ft_env_find(env, "PATH") == -1 && ft_strncmp(str, "minishell", 20))))
		{
			signal(SIGINT, SIG_IGN);
			signal(SIGQUIT, SIG_IGN);
		}
	}
	else
	{
		signal(SIGINT, ft);
		signal(SIGQUIT, ft1);
	}
}

int			create_another(t_parse *pars)
{
	char	*str;
	pid_t	pid;
	int		r;

	str = pars->arg[0];
	test(str, 1, pars->env);
	if ((pid = fork()) == 0)
	{
		if (*str && (*str == '/' || (*str == '.' && *(str + 1) == '/') ||
		ft_env_find(pars->env, "PATH") == -1))
			exit(with_path(pars));
		exit(without_path(pars));
	}
	else
	{
		if (pid != -1)
			waitpid(pid, &r, 0);
		else
			return (ft_errors_std(1, EFORKC, pars));
		test(str, 0, pars->env);
		if (g_cat)
			return (g_cat);
		return (WEXITSTATUS(r));
	}
	return (0);
}
