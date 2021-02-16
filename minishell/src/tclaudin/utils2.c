/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:46:45 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/08 18:35:01 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_std_fd	*copy_std_fd(void)
{
	t_std_fd *std;

	if (!(std = (t_std_fd*)ft_calloc(1, sizeof(t_std_fd))))
		return (NULL);
	std->fd_one = dup(1);
	std->fd_zero = dup(0);
	return (std);
}

void		ft_reset_fd(t_std_fd *std, t_std_fd *now)
{
	dup2(std->fd_zero, 0);
	dup2(std->fd_one, 1);
	if (now->fd_one != -1)
		close(now->fd_one);
	if (now->fd_zero != -1)
		close(now->fd_zero);
}

int			ft_redirects(char **str, t_env_var **env, t_std_fd *now, t_parse *p)
{
	int		red;
	char	*s;

	red = 0;
	s = *str;
	if (*s == '<')
		return (ft_inp_redirect(str, env, now, p));
	while (*s == '>')
	{
		red++;
		s++;
	}
	if (red == 1)
		return (ft_trc_redirect(str, env, now, p));
	if (red == 2)
		return (ft_add_redirect(str, env, now, p));
	*s = 0;
	*str = s - 1;
	return (ft_errors_dp(">>", p));
}

int			save_ret_code(t_parse *pars, size_t n)
{
	t_env_var	*env;
	int			ret;

	ret = 0;
	if (pars->ret_code == 0)
	{
		ret = ft_std_tokens(pars, n);
		if (ret == -1)
			ret = 0;
		pars->ret_code = ret;
	}
	env = pars->env[1];
	free(env->value);
	if (!(env->value = ft_itoa(pars->ret_code)))
		return (1);
	pars->env[1] = env;
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	return (ret);
}

void		destroy_envp(char **env)
{
	int i;

	i = 0;
	if (env)
	{
		while (env[i])
		{
			free(env[i]);
			i++;
		}
		free(env);
	}
}
