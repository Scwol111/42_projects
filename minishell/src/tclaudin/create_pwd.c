/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 18:20:13 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/02 11:56:37 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		create_pwd(t_parse *pars, size_t n)
{
	ft_pwd();
	if (pars && n)
		return (0);
	return (0);
}