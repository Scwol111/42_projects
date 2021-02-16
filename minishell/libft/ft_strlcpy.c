/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tclaudin <tclaudin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:57:17 by tclaudin          #+#    #+#             */
/*   Updated: 2020/09/24 15:58:38 by tclaudin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = -1;
	while (size != 0 && ++i < size - 1)
	{
		*(dst + i) = *(src + i);
		if (*(dst + i) == 0)
			break ;
	}
	if (i == size - 1 && size != 0)
		*(dst + i) = 0;
	return (ft_strlen(src));
}
