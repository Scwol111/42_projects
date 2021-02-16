/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:10:51 by tclaudin          #+#    #+#             */
/*   Updated: 2021/01/06 13:22:17 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		pipes(t_parse *pars, size_t n)
{
	int		fd[2];
	int		ret;
	pid_t	pid;

	pipe(fd);
	pars->pipe = 1;
	if ((pid = fork()) == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		ret = ft_std_tokens(pars, n);
		close(fd[1]);
		exit(ret);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		waitpid(pid, &ret, 0);
		close(fd[0]);
	}
	return (WEXITSTATUS(ret));
}
