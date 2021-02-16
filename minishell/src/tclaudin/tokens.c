/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 17:25:42 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/09 19:03:07 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_std_tokens(t_parse *pars, size_t n)
{
	char *str;

	if (n > 0 && (str = pars->arg[0]))
	{
		if (!ft_strncmp(str, "echo", 10))
			return (create_echo(pars));
		if (!ft_strncmp(str, "cd", 10))
			return (create_cd(pars, n));
		if (!ft_strncmp(str, "env", 10))
			return (create_envp(pars, n));
		if (!ft_strncmp(str, "exit", 10))
			return (create_exit(pars, n));
		if (!ft_strncmp(str, "export", 10))
			return (create_export(pars, n));
		if (!ft_strncmp(str, "pwd", 10))
			return (create_pwd(pars, n));
		if (!ft_strncmp(str, "unset", 10))
			return (create_unset(pars, n));
		return (create_another(pars));
	}
	return (-1);
}
