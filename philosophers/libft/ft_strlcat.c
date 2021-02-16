/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:04:11 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:34 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;
	size_t a;

	j = 0;
	a = ft_strlen(src);
	if (size < ft_strlen(dst))
		a += size;
	else
		a += ft_strlen(dst);
	i = ft_strlen(dst);
	if (i < size - 1 && size > 0)
	{
		while (i < size - 1 && size != 0)
		{
			*(dst + i) = *(src + j++);
			if (*(dst + i) == 0)
				break ;
			i++;
		}
		*(dst + i) = 0;
	}
	return (a);
}
