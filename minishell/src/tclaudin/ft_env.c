/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:13:28 by tclaudin          #+#    #+#             */
/*   Updated: 2020/11/23 12:48:55 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		destroy_env(t_env_var **env)
{
	int	i;

	i = 0;
	if (env != NULL)
	{
		while (env[i] != NULL)
		{
			free(env[i]->name);
			free(env[i]->value);
			free(env[i]);
			i++;
		}
		free(env);
	}
}

static void	ft_env_norm_kostil(char **str1, char **str2, int *i)
{
	if (*i == 0)
		*str1 = ft_strdup("~");
	if (*i == 1)
	{
		*str1 = ft_strdup("?");
		*str2 = ft_strdup("0");
	}
}

t_env_var	**create_env(char **env)
{
	t_env_var	**ar;
	int			i;
	size_t		sz;

	sz = BUFFER_SIZE * 2 + 3;
	if (!(ar = (t_env_var**)ft_calloc(sz, sizeof(*ar))))
		return (NULL);
	i = -1;
	while (env[++i])
	{
		if (!(ar[i] = (t_env_var*)malloc(sizeof(t_env_var))))
			return (NULL);
		if (i == 0 || i == 1)
			ft_env_norm_kostil(&ar[i]->name, &ar[i]->value, &i);
		else
		{
			ar[i]->value = ft_strdup(ft_strchr(env[i], '=') + 1);
			*ft_strchr(env[i], '=') = 0;
			ar[i]->name = ft_strdup(env[i]);
			if (ft_strncmp(ar[i]->name, "HOME", 10) == 0)
				ar[0]->value = ft_strdup(ar[i]->value);
		}
	}
	return (ar);
}

int			ft_env_find(t_env_var **env, char *str)
{
	size_t	i;

	i = 1;
	while (env[i])
	{
		if (ft_strnstr(env[i]->name, str, BUFFER_SIZE * 5) &&
		(ft_strlen(env[i]->name) == ft_strlen(str)))
			return (i);
		i++;
	}
	return (-1);
}
