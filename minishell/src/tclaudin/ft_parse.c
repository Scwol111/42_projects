/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 11:30:15 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/09 18:57:20 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parse	*ft_remade_args(t_parse *pars)
{
	size_t i;

	i = 0;
	if (!(pars->arg = (char**)ft_calloc(pars->sz, sizeof(char*))))
		return (pars);
	while (i < pars->sz)
		pars->arg[i++] = NULL;
	if (!(pars->cur_size = (size_t*)ft_calloc(pars->sz, sizeof(size_t))))
		return (pars);
	if (!(pars->size = (size_t*)ft_calloc(pars->sz, sizeof(size_t))))
		return (pars);
	pars->ret_code = 0;
	return (pars);
}

t_parse	create_pars(t_env_var ***env, t_std_fd *std)
{
	t_parse pars;
	size_t	i;

	i = 0;
	pars.sz = BUFFER_SIZE;
	pars.env = *env;
	pars.envp = env;
	pars.fl = 0;
	pars.ret_code = 0;
	pars.std_fd = std;
	pars.now_fd.fd_one = -1;
	pars.now_fd.fd_zero = -1;
	pars.pipe = 0;
	if (!(pars.arg = (char**)ft_calloc(pars.sz, sizeof(char*))))
		return (pars);
	while (i < pars.sz)
		pars.arg[i++] = NULL;
	if (!(pars.cur_size = (size_t*)ft_calloc(pars.sz, sizeof(size_t))))
		return (pars);
	if (!(pars.size = (size_t*)ft_calloc(pars.sz, sizeof(size_t))))
		return (pars);
	return (pars);
}

void	destroy_args(t_parse *pars, size_t n)
{
	size_t i;

	i = 0;
	if (pars->size)
		free(pars->size);
	if (pars->cur_size)
		free(pars->cur_size);
	if (n > 0)
	{
		while (i <= n)
			free(pars->arg[i++]);
		free(pars->arg);
	}
}

t_parse	ft_reload_parse(t_parse *par)
{
	t_parse	pars;
	size_t	i;

	pars.sz = par->sz + BUFFER_SIZE;
	if (!(pars.arg = (char**)ft_calloc(pars.sz, sizeof(char*))) ||
	!(pars.cur_size = (size_t*)ft_calloc(pars.sz, sizeof(size_t))) ||
	!(pars.size = (size_t*)ft_calloc(pars.sz, sizeof(size_t))))
		return (pars);
	i = -1;
	while (++i + 1 < pars.sz)
	{
		if (i < par->sz)
		{
			pars.arg[i] = ft_strdup(par->arg[i]);
			pars.size[i] = par->size[i];
			pars.cur_size[i] = par->cur_size[i];
		}
		else
			pars.arg[i] = NULL;
	}
	destroy_args(par, par->sz);
	return (pars);
}

int		ft_parse(char *str, t_env_var ***env, t_std_fd *fd)
{
	t_parse	par;
	size_t	i;

	i = 0;
	par = create_pars(env, fd);
	str = ft_skip_space(str);
	while (*str)
	{
		if (ft_strchr(SPECIALS, *str))
			par.ret_code = ft_specials(&par, &str, &i, *str);
		else
		{
			if (par.cur_size[i] + 1 >= par.size[i])
				par.arg[i] = ft_remade(par.arg[i], &par.size[i]);
			par.arg[i][par.cur_size[i]++] = *str;
			par.fl = 1;
		}
		str++;
	}
	save_ret_code(&par, i + 1);
	destroy_args(&par, i + 1);
	*par.envp = par.env;
	ft_reset_fd(par.std_fd, &par.now_fd);
	return (0);
}
