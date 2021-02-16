/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:19:40 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/03 00:28:43 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_export(t_parse *pars, size_t n)
{
	int error_cod;
	int	ret;

	error_cod = 0;
	ret = export(pars, pars->envp, pars->arg + 1, error_cod);
	pars->env = *pars->envp;
	if (pars && n)
		return (ret);
	return (ret);
}
