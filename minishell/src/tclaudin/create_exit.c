/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:19:28 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/03 00:34:13 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_exit(t_parse *pars, size_t n)
{
	int		ret;

	ret = ft_exit(pars->arg + 1, pars);
	if (!pars->pipe && ret != -1)
		exit(ret);
	if (ret == -1)
		return (1);
	if (n)
		return (ret);
	return (ret);
}
