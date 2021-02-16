/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 13:59:14 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:18 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_freeble(char **arr, size_t i)
{
	arr[i] = NULL;
	while (*arr != NULL)
	{
		free(*arr);
		arr++;
	}
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * (ft_strlen(s) / 2) + 1)))
		return (NULL);
	while (*s != 0)
	{
		if (*s != c)
		{
			j = 0;
			if (!(str = (char*)malloc(ft_strlen(s) + 1)))
				return (ft_freeble(res, i));
			while (*s != c && *s != 0)
				str[j++] = *(s++);
			str[j] = 0;
			res[i++] = str;
		}
		else
			s++;
	}
	res[i] = NULL;
	return (res);
}
