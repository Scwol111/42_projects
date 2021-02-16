/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 16:14:57 by loscar            #+#    #+#             */
/*   Updated: 2020/12/03 00:28:29 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		flag_pocherk_fun(char **input, int i, int k, int error_flag)
{
	if (input[i][k] == '_' && error_flag != 0)
		return (1);
	return (0);
}

static int		error_flag_fun(char **input, int i)
{
	if (input[i][0] == '_')
		return (0);
	if (input[i][0] == '=')
		return (1);
	if (ft_isalpha(input[i][0]))
		return (2);
	return (100);
}

static	int		flag_fun(char **input, int i, int k, int *flag)
{
	if (input[i][k] == '=')
	{
		*flag = 1;
		return (1);
	}
	return (0);
}

void			export_pars(t_parse *pars, int i, int *error_cod, int *flag)
{
	int		k;
	int		error_flag;
	char	**input;
	int		flag_pocherk;

	input = pars->arg + 1;
	k = -1;
	while (input[i][++k] && ft_strncmp(input[i], "_", ft_strlen(input[i])))
	{
		error_flag = error_flag_fun(input, i);
		flag_pocherk = flag_pocherk_fun(input, i, k, error_flag);
		if ((error_flag != 2 || !ft_isalnum(input[i][k]))
		&& !ft_isalpha(input[i][k]) && input[i][k] != '_'
		&& (input[i][k] != '=' || error_flag == 1)
		&& (error_flag != 0 || !ft_isalnum(input[i][k]))
		&& (flag_pocherk != 1 || !ft_isalnum(input[i][k])))
		{
			*error_cod = 1;
			error_export(1, input[i], pars);
			break ;
		}
		if (flag_fun(input, i, k, flag))
			break ;
	}
}
