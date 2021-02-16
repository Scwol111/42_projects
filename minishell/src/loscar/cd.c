/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:15:57 by loscar            #+#    #+#             */
/*   Updated: 2020/12/02 21:40:42 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		new_pwd(t_env_var **env)
{
	int		c;
	char	*dup;

	c = ft_env_find(env, "PWD");
	if (c != -1)
	{
		dup = ft_strdup(getcwd(NULL, 0));
		if (env[c]->value != NULL)
			free(env[c]->value);
		env[c]->value = dup;
	}
}

static void		old_pwd(t_env_var **env)
{
	int		c;
	char	*dup;

	c = ft_env_find(env, "OLDPWD");
	dup = ft_strdup(getcwd(NULL, 0));
	if (env[c]->value != NULL)
		free(env[c]->value);
	env[c]->value = dup;
}

int				ft_cd(char *path, t_env_var **env, t_parse *pars)
{
	int c;
	int fd;

	if ((fd = open(path, O_DIRECTORY | O_RDONLY)) < 0 && path != NULL)
	{
		error_cd(11, path, pars);
		return (1);
	}
	close(fd);
	c = ft_env_find(env, "HOME");
	if (c == -1 && path == NULL)
	{
		error_cd(1, "", pars);
		return (1);
	}
	old_pwd(env);
	if (path == NULL)
		chdir(env[c]->value);
	chdir(path);
	new_pwd(env);
	return (0);
}
