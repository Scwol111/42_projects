/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 13:38:54 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:26 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*st;
	size_t	i;

	i = 0;
	st = (char*)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!st)
		return (NULL);
	while (*(src + i) != 0)
	{
		*(st + i) = *(src + i);
		i++;
	}
	*(st + i) = 0;
	return (st);
}
