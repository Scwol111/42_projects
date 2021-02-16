/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 14:06:39 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:59:07 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*st;
	size_t	i;
	size_t	j;

	st = (char*)malloc(len + 1);
	if (!st)
		return (NULL);
	i = 0;
	j = 0;
	while (*(s + i) != 0)
	{
		if (i >= start && j < len)
			*(st + j++) = *(s + i);
		i++;
	}
	*(st + j) = 0;
	return (st);
}
