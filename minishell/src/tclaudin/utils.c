/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:24:03 by tclaudin          #+#    #+#             */
/*   Updated: 2020/11/01 18:41:53 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_skip_space(char *str)
{
	while (*str != 0 && *str == ' ')
		str++;
	return (str);
}

char	*ft_next_word(char *str)
{
	while (*str != 0 && *str != ' ' && *str != '\n' && *str != '\t' &&
	*str != '\v' && *str != '\f' && *str != '\r')
		str++;
	return (str);
}

int		ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		ft_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

char	*ft_remade(char *str, size_t *old_size)
{
	char *new_str;

	*old_size += BUFFER_SIZE;
	if (!(new_str = (char*)ft_calloc(*old_size, sizeof(char))))
		return (NULL);
	if (str)
	{
		ft_strlcpy(new_str, str, *old_size);
		free(str);
	}
	return (new_str);
}
