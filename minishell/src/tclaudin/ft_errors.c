/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:05 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/08 18:11:31 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_errors_std(int ret, char *err, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	ft_putstr_fd("lotcshell: ", 1);
	ft_putendl_fd(err, 1);
	return (ret);
}

int		ft_errors_exec(char *err, t_parse *pars)
{
	int fd;

	ft_reset_fd(pars->std_fd, &pars->now_fd);
	ft_putstr_fd("lotcshell: ", 1);
	ft_putstr_fd(err, 1);
	if ((fd = open(err, O_RDONLY | O_DIRECTORY)) < 0)
	{
		ft_putstr_fd(": ", 1);
		ft_putendl_fd(strerror(errno), 1);
		if (errno == 2)
			return (127);
	}
	else
		ft_putendl_fd(": is a directory", 1);
	return (126);
}

int		ft_errors_redir(char c, char *str, t_parse *pars, short type)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	ft_putstr_fd("lotcshell: ", 1);
	if (type == 1)
	{
		ft_putstr_fd("syntax error near unexpected token `", 1);
		if (c == 0 || c == '\n')
			ft_putstr_fd("newline", 1);
		else
			ft_putchar_fd(c, 1);
		ft_putendl_fd("'", 1);
		return (258);
	}
	ft_putstr_fd(str, 1);
	ft_putstr_fd(": ", 1);
	ft_putendl_fd(strerror(errno), 1);
	return (1);
}

int		ft_errors_dp(char *str, t_parse *pars)
{
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	ft_putstr_fd("lotcshell: ", 1);
	ft_putstr_fd("syntax error near unexpected token `", 1);
	ft_putstr_fd(str, 1);
	ft_putendl_fd("'", 1);
	return (258);
}
