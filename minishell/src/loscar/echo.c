/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 19:15:41 by loscar            #+#    #+#             */
/*   Updated: 2020/12/02 21:40:53 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_echo(char *str, int flag)
{
	ft_putstr_fd(str, 1);
	if (flag == 0)
	{
		g_n = 0;
		write(1, "\n", 1);
	}
	else
		g_n = 1;
	return (0);
}
