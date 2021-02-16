/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:18:31 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/02 19:08:52 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_cd(t_parse *pars, size_t n)
{
	ft_cd(pars->arg[1], pars->env, pars);
	if (pars && n)
		return (0);
	return (0);
}
