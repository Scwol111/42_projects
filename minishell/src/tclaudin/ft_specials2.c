/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specials2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:15:37 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/08 16:35:09 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_sp_slash(t_parse *pars, char **str_org, size_t *i)
{
	char *str;

	str = *str_org;
	str++;
	if (*str)
	{
		if (pars->cur_size[*i] + 1 >= pars->size[*i])
			pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
		pars->arg[*i][pars->cur_size[*i]++] = *(str);
		*str_org = str;
		pars->fl = '\1';
	}
	return (0);
}

int		ft_sp_tilda(t_parse *pars, char **str_org, size_t *i)
{
	char	*str;
	int		fl;

	str = *str_org;
	fl = 1;
	if (!pars->fl)
	{
		if (!*(str + 1) || *(str + 1) == ' ' || *(str + 1) == '/')
		{
			pars->cur_size[*i] += ft_strlen(pars->env[0]->value);
			while (pars->cur_size[*i] >= pars->size[*i])
				pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
			ft_strlcat(pars->arg[*i], pars->env[0]->value, pars->size[*i]);
			fl = 0;
		}
	}
	if (fl)
	{
		if (pars->cur_size[*i] + 1 >= pars->size[*i])
			pars->arg[*i] = ft_remade(pars->arg[*i], &pars->size[*i]);
		pars->arg[*i][pars->cur_size[*i]++] = *str;
	}
	pars->fl = 1;
	return (0);
}

int		ft_sp_dots(t_parse *pars, char **str_org, size_t *i)
{
	char		*str;
	int			fl;

	str = *str_org + 1;
	fl = 0;
	if (save_ret_code(pars, *i + 1) == -1)
	{
		free(pars->env[1]->value);
		if (!(pars->env[1]->value = ft_itoa(258)))
			return (258);
		if (*(str) == ';')
			fl = 1;
		*str = 0;
		*str_org = str - 1;
		if (fl)
			return (ft_errors_dp(";;", pars));
		return (ft_errors_dp(";", pars));
	}
	destroy_args(pars, *i);
	*i = 0;
	pars = ft_remade_args(pars);
	str = ft_skip_space(str);
	*str_org = str - 1;
	ft_reset_fd(pars->std_fd, &pars->now_fd);
	return (0);
}

int		ft_sp_pipe(t_parse *pars, char **str_org, size_t *i)
{
	char		*str;
	int			fl;

	str = *str_org + 1;
	fl = 0;
	pipes(pars, *i);
	if (!pars->arg[0])
	{
		free(pars->env[1]->value);
		if (!(pars->env[1]->value = ft_itoa(258)))
			return (258);
		if (*(str) == '|')
			fl = 1;
		*str = 0;
		*str_org = str - 1;
		if (fl)
			return (ft_errors_dp("||", pars));
		return (ft_errors_dp("|", pars));
	}
	destroy_args(pars, *i);
	*i = 0;
	pars = ft_remade_args(pars);
	str = ft_skip_space(str);
	*str_org = str - 1;
	return (0);
}
