/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:20:26 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/02 19:09:22 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_unset(t_parse *pars, size_t n)
{
	unset(pars, pars->envp, pars->arg + 1);
	pars->env = *pars->envp;
	if (pars && n)
		return (0);
	return (0);
}
