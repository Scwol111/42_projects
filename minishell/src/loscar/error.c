/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 16:11:04 by loscar            #+#    #+#             */
/*   Updated: 2020/12/03 00:35:19 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_export(int flag, char *comand, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	if (flag == 1)
	{
		ft_putstr_fd("lotcshell: export: '", 1);
		ft_putstr_fd(comand, 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
	}
}

void	error_unset(int flag, char *comand, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	if (flag == 1)
	{
		ft_putstr_fd("lotcshell: unset: '", 1);
		ft_putstr_fd(comand, 1);
		ft_putstr_fd("': not a valid identifier\n", 1);
	}
}

void	error_cd(int flag, char *comand, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	if (flag == 1)
		ft_putstr_fd("lotcshell: cd: HOME not set\n", 1);
	if (flag == 11)
	{
		ft_putstr_fd("lotcshell: cd: ", 1);
		ft_putstr_fd(comand, 1);
		ft_putstr_fd(": No such file or directory\n", 1);
	}
}

int		error(int flag, char *comand, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	if (flag == 0)
	{
		ft_putstr_fd("lotcshell: ", 1);
		ft_putstr_fd(comand, 1);
		ft_putstr_fd(": command not found\n", 1);
		return (127);
	}
	return (0);
}

int		error_exit(int flag, char *comand, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	if (flag == 255)
	{
		ft_putstr_fd("lotcshell: exit: ", 1);
		ft_putstr_fd(comand, 1);
		ft_putstr_fd(": numeric argument required\n", 1);
		return (255);
	}
	if (flag == -1)
	{
		ft_putstr_fd("lotcshell: exit: too many arguments\n", 1);
		return (-1);
	}
	return (0);
}
