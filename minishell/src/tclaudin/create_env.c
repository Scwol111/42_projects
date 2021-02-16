/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:19:09 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/01 16:30:35 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_env_out(t_env_var **env)
{
	int	i;

	i = 2;
	while (env[i])
	{
		if (env[i]->value)
		{
			ft_putstr_fd(env[i]->name, 1);
			ft_putstr_fd("=", 1);
			ft_putendl_fd(env[i]->value, 1);
		}
		i++;
	}
}

int			create_envp(t_parse *pars, size_t n)
{
	ft_env_out(pars->env);
	if (pars && n)
		return (0);
	return (0);
}
