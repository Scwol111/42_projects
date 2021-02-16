/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:12:13 by tclaudin          #+#    #+#             */
/*   Updated: 2020/12/03 03:05:54 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_rd_specials(char **n, char **str, t_size *size, t_env_var **env)
{
	if (**str == '\\')
		return (ft_rd_slash(n, str, size));
	if (**str == '\'')
		return (ft_rd_qoutes(n, str, size));
	if (**str == '\"')
		return (ft_rd_dquote(n, str, size, env));
	if (**str == '$')
		return (ft_rd_dollar(n, str, size, env));
	if (**str == '~')
		return (ft_rd_tilda(n, str, size, env));
	return (1);
}

static char	*find_file_name(char **string, t_env_var **env)
{
	char	*name;
	char	*str;
	t_size	size;

	str = *string;
	size.size = 0;
	size.curr = 0;
	name = NULL;
	while (*str && !ft_strchr(RD_OUT, *str))
	{
		if (ft_strchr(RD_SPECIALS, *str))
			ft_rd_specials(&name, &str, &size, env);
		else
		{
			if (size.curr + 1 >= size.size)
				name = ft_remade(name, &size.size);
			name[size.curr++] = *str;
		}
		str++;
	}
	*string = str;
	return (name);
}

int			ft_trc_redirect(char **s, t_env_var **e, t_std_fd *now, t_parse *p)
{
	char	*str;
	char	*name;
	int		fd;

	str = *s + 1;
	str = ft_skip_space(str);
	name = find_file_name(&str, e);
	if (name)
	{
		if ((fd = open(name, O_RDWR | O_TRUNC)) < 0)
			if ((fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE)) < 0)
				fd = -1;
		if (fd > 0)
			dup2(fd, 1);
		free(name);
		*s = str;
	}
	else
		return (ft_errors_redir(*str, NULL, p, 1));
	if (fd < 0)
		return (ft_errors_redir(*str, name, p, 2));
	if (now->fd_one != -1)
		close(now->fd_one);
	now->fd_one = fd;
	return (0);
}

int			ft_add_redirect(char **s, t_env_var **e, t_std_fd *now, t_parse *p)
{
	char	*str;
	char	*name;
	int		fd;

	str = *s + 2;
	str = ft_skip_space(str);
	name = find_file_name(&str, e);
	if (name)
	{
		if ((fd = open(name, O_RDWR | O_APPEND)) < 0)
			if ((fd = open(name, O_RDWR | O_CREAT, S_IREAD | S_IWRITE)) < 0)
				fd = -1;
		if (fd > 0)
			dup2(fd, 1);
		free(name);
		*s = str;
	}
	else
		return (ft_errors_redir(*str, NULL, p, 1));
	if (fd < 0)
		return (ft_errors_redir(*str, name, p, 2));
	if (now->fd_one != -1)
		close(now->fd_one);
	now->fd_one = fd;
	return (0);
}

int			ft_inp_redirect(char **s, t_env_var **e, t_std_fd *now, t_parse *p)
{
	char	*str;
	char	*name;
	int		fd;

	str = *s + 1;
	str = ft_skip_space(str);
	name = find_file_name(&str, e);
	if (name)
	{
		if ((fd = open(name, O_RDONLY)) < 0)
			if ((fd = open(name, O_DIRECTORY | O_RDONLY)) < 0)
				fd = -1;
		if (fd > 0)
			dup2(fd, 0);
		free(name);
		*s = str;
	}
	else
		return (ft_errors_redir(*str, NULL, p, 1));
	if (fd < 0)
		return (ft_errors_redir(*str, name, p, 2));
	if (now->fd_zero != -1)
		close(now->fd_zero);
	now->fd_zero = fd;
	return (0);
}
