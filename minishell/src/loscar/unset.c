/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: loscar <loscar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:43:58 by loscar            #+#    #+#             */
/*   Updated: 2020/12/02 19:38:32 by loscar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		unset(t_parse *pars, t_env_var ***env, char **input)
{
	int i;
	int k;

	i = 0;
	while (input[i])
	{
		k = 0;
		while (input[i][k])
		{
			if (!ft_isalpha(input[i][k]) && input[i][k] != '_')
			{
				error_unset(1, input[i], pars);
				break ;
			}
			k++;
		}
		ft_del_env(env, input[i]);
		i++;
	}
	return (1);
}
